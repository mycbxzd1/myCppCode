#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
可生成任意规模、多样化的 labels.csv 训练集
示例：
    python make_labels.py --keep 5000 --temp 5000 --out labels_10000.csv
"""

import random
import argparse
import csv
import itertools
from pathlib import Path

# ---------- 样本模板 ----------
KEEP_TYPES = {
    "code": ["main.cpp", "utils.py", "server.go", "App.java", "index.ts"],
    "config": ["app.yaml", "settings.json", "nginx.conf", "redis.conf"],
    "docs": ["README.md", "CHANGELOG.md", "部署指南.md", "architecture.pdf"],
    "assets": ["logo.svg", "banner.png", "intro.mp4", "Roboto-Bold.ttf"],
    "sql": ["20250725_create_user.sql", "20250726_add_index.sql"],
}

TEMP_TYPES = {
    "build": ["main.o", "main.obj", "libapp.a", "app.dll", "app.exe"],
    "cache": [".eslintcache", "chunk-XYZ.js.map", "cached_123.tmp"],
    "logs": ["app.log", "error.log.2025-07-24", "npm-debug.log"],
    "tmp": ["upload_123.part", "Ubuntu.iso.crdownload", "session_987.tmp"],
    "swp": ["main.cpp.swp", "~$方案.docx", ".#方案.docx"],
}

WALKERS = [
    "src", "lib", "core", "utils", "api", "frontend", "backend", "测试",
    "组件", "模块", "功能A", "功能B", "2025-07-25", "v2.3.0", "draft",
    "docs", "assets", "build", "dist", "output", "tmp", "cache"
]
# --------------------------------

def sample(pool, k):
    """从 pool 无限循环取元素，截断到 k 个"""
    return list(itertools.islice(itertools.cycle(pool), k))

def gen_paths(base: str, names, depth_choices):
    for name in names:
        depth = random.choice(depth_choices)
        folders = [random.choice(WALKERS) for _ in range(depth)]
        yield f"{base}/{'/'.join(folders)}/{name}"

def build_rows(keep_n: int, temp_n: int):
    rows = []
    # 保留样本
    for items in KEEP_TYPES.values():
        rows.extend((p, 0) for p in gen_paths(
            "project",
            sample(items, keep_n // len(KEEP_TYPES)),
            [1, 2, 3]
        ))
    # 可删样本
    for items in TEMP_TYPES.values():
        rows.extend((p, 1) for p in gen_paths(
            "project",
            sample(items, temp_n // len(TEMP_TYPES)),
            [2, 3, 4]
        ))
    random.shuffle(rows)
    return rows

def main(keep_n: int, temp_n: int, out_file: str):
    random.seed(0xCADE)
    rows = build_rows(keep_n, temp_n)
    with Path(out_file).open("w", newline='', encoding="utf-8") as f:
        csv.writer(f).writerows(rows)
    print(f"✅  已生成 {len(rows)} 行 -> {out_file}")

if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--keep", type=int, default=2000, help="保留样本数")
    ap.add_argument("--temp", type=int, default=2000, help="可删样本数")
    ap.add_argument("--out",  default="labels.csv", help="输出文件名")
    args = ap.parse_args()                       # ← 解析
    main(keep_n=args.keep,                       # ← 参数对齐
         temp_n=args.temp,
         out_file=args.out)