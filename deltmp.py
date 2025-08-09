#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
清理脚本：
1) 删除文件名包含临时/测试关键词的文件（可配置），同时跳过脚本自身和日志文件
2) 检测算法竞赛 I/O 文件是否成对（.in/.out、.dat/.ans 等）
3) 轻量级神经网络（字符 n‑gram + 逻辑回归）辅助判别：
   - 置信度 >0.8 直接删除，<0.4 直接保留，其余人工确认
4) Windows 如遇文件占用，可交互式选择强删 (/F)

依赖：scikit-learn, joblib
"""

import os
import sys
import ctypes
import subprocess
import logging
import argparse
from pathlib import Path
from datetime import datetime
from typing import Optional

# Windows 专用读取按键
import msvcrt
import joblib

# ---------- 配置 ----------
DEFAULT_KEYWORDS = ['temp', 'tmp', 'test', 'debug', 'bak', 'backup', '~', '.swp', '#']
LOG_FILENAME = 'clean_temp_files.log'
INPUT_EXTS = ['.in', '.dat', '.input']
OUTPUT_EXTS = ['.out', '.ans', '.output']
MODEL_FILENAME = 'temp_clf.pkl'
# --------------------------

# ---------- 权限 ----------
def is_admin() -> bool:
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except Exception:
        return False


def relaunch_as_admin():
    params = ' '.join([f'"{arg}"' for arg in sys.argv])
    ctypes.windll.shell32.ShellExecuteW(
        None, "runas", sys.executable, params, None, 1)
    sys.exit(0)
# --------------------------

# ---------- 日志 ----------
def setup_logger(log_path: Path):
    logger = logging.getLogger('cleaner')
    logger.setLevel(logging.DEBUG)
    fh = logging.FileHandler(log_path, encoding='utf-8')
    fh.setFormatter(logging.Formatter(
        '%(asctime)s [%(levelname)s] %(message)s', '%Y-%m-%d %H:%M:%S'))
    ch = logging.StreamHandler(sys.stdout)
    ch.setLevel(logging.INFO)
    ch.setFormatter(logging.Formatter(
        '%(asctime)s [%(levelname)s] %(message)s', '%Y-%m-%d %H:%M:%S'))
    logger.addHandler(fh)
    logger.addHandler(ch)
    return logger
# --------------------------

# ---------- 轻量级分类器 ----------
class TempFileClassifier:
    """n‑gram 路径二分类模型（本地推断）"""

    def __init__(self, model_path: Path):
        self.model: Optional[object] = None
        if model_path.exists():
            try:
                self.model = joblib.load(model_path)
            except Exception as e:
                print(f"⚠️  模型加载失败: {e}")

    def predict_proba(self, path: Path) -> float:
        if not self.model:
            return 0.0
        txt = str(path).replace('\\', '/')
        return float(self.model.predict_proba([txt])[0][1])
# --------------------------------

# ---------- 功能函数 ----------
def is_temp_by_keyword(name: str, keywords: list) -> bool:
    lower = name.lower()
    return any(k.lower() in lower for k in keywords)


def interactive_menu(options: list[str]) -> int:
    idx = 0
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        print("请选择：")
        for i, opt in enumerate(options):
            mark = "⬤" if i == idx else "○"
            print(f"  {mark} {opt}")
        key = msvcrt.getch()
        if key == b'\xe0':        # 方向键
            k2 = msvcrt.getch()
            if k2 in (b'H', b'K'):    # 上/左
                idx = (idx - 1) % len(options)
            elif k2 in (b'P', b'M'):  # 下/右
                idx = (idx + 1) % len(options)
        elif key in (b'\r', b'\n'):
            return idx


def force_delete(path: Path, logger) -> bool:
    try:
        subprocess.run(f'del /F "{path}"',
                       shell=True, check=True,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        logger.info(f"强制删除成功: {path}")
        return True
    except subprocess.CalledProcessError as e:
        logger.error(f"强制删除失败: {path}，错误: {e}")
        return False


def remove_file(path: Path, logger, counters: dict):
    try:
        path.unlink()
        counters['deleted'] += 1
        logger.info(f"已删除: {path}")
    except PermissionError:
        logger.warning(f"删除失败（被占用）: {path}")
        choice = interactive_menu(["跳过删除", "强制删除 (/F)"])
        if choice == 1 and force_delete(path, logger):
            counters['deleted'] += 1
        else:
            counters['errs'] += 1
    except Exception as e:
        counters['errs'] += 1
        logger.error(f"删除失败: {path}，错误: {e}")
# --------------------------

# ---------- 清理逻辑 ----------
def should_delete(path: Path, keywords: list,
                  clf: TempFileClassifier) -> bool:
    """综合关键词 + ML 判断 + 人工确认"""
    if is_temp_by_keyword(path.name, keywords):
        return True

    prob = clf.predict_proba(path)
    if prob >= 0.8:
        return True
    if prob <= 0.4:
        return False

    # 0.4~0.8 走人工确认
    print(f"\n⚖️  {path} 判定置信度 {prob:.2f}")
    choice = interactive_menu(["保留", "删除"])
    return choice == 1


def clean_temp_files(root: Path, keywords: list,
                     logger, counters: dict, clf: TempFileClassifier):
    script = Path(__file__).resolve()
    logf = root / LOG_FILENAME
    for p in root.rglob('*'):
        if not p.is_file():
            continue
        if p.resolve() in (script, logf):
            continue
        counters['scanned'] += 1
        if should_delete(p, keywords, clf):
            remove_file(p, logger, counters)


def clean_incomplete_pairs(root: Path, logger, counters: dict):
    for d in [root] + [x for x in root.rglob('*') if x.is_dir()]:
        inputs = {f.stem for f in d.iterdir()
                  if f.suffix.lower() in INPUT_EXTS}
        outputs = {f.stem for f in d.iterdir()
                   if f.suffix.lower() in OUTPUT_EXTS}
        only_in = inputs - outputs
        only_out = outputs - inputs
        for base in only_in:
            for ext in INPUT_EXTS:
                f = d / (base + ext)
                if f.exists():
                    remove_file(f, logger, counters)
        for base in only_out:
            for ext in OUTPUT_EXTS:
                f = d / (base + ext)
                if f.exists():
                    remove_file(f, logger, counters)
# --------------------------

# ---------- main ----------
def main(root: Path, keywords: list):
    if os.name == 'nt' and not is_admin():
        print("需要管理员权限，正在以管理员身份重启...")
        relaunch_as_admin()

    clf = TempFileClassifier(root / MODEL_FILENAME)
    logf = root / LOG_FILENAME
    logger = setup_logger(logf)
    counters = {'scanned': 0, 'deleted': 0, 'errs': 0}

    logger.info(f"开始清理：根目录 = {root.resolve()}")
    start = datetime.now()

    clean_temp_files(root, keywords, logger, counters, clf)
    clean_incomplete_pairs(root, logger, counters)

    took = datetime.now() - start
    logger.info("=== 清理完成 ===")
    logger.info(f"总扫描文件: {counters['scanned']}")
    logger.info(f"总删除文件: {counters['deleted']}")
    logger.info(f"失败数: {counters['errs']}")
    logger.info(f"耗时: {took}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="清理临时文件和不完整 I/O 对")
    parser.add_argument('--root', '-r', type=Path,
                        default=Path('.'), help='根目录')
    parser.add_argument('--keywords', '-k', nargs='+',
                        default=DEFAULT_KEYWORDS, help='临时关键词列表')
    args = parser.parse_args()

    try:
        main(args.root, args.keywords)
    finally:
        if os.name == 'nt':
            input("清理完成，按回车键退出...")
