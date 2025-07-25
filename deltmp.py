# ---------- 新增 import ----------
import joblib
from typing import Optional

# ---------- 模型加载 ----------
class TempFileClassifier:
    """本地 n‑gram 文件路径二分类模型"""
    def __init__(self, model_path: Path):
        self.model: Optional[object] = None
        if model_path.exists():
            try:
                self.model = joblib.load(model_path)
            except Exception as e:
                print(f"⚠️ 模型加载失败: {e}")

    def predict_proba(self, path: Path) -> float:
        if not self.model:
            return 0.0       # 没模型就当作“保留”
        # 转成统一的正斜杠，避免 \ 与 / 不一致影响特征
        txt = str(path).replace('\\', '/')
        prob = self.model.predict_proba([txt])[0][1]   # 取“被删除”的概率
        return float(prob)

# ---------- 更新 is_temp_file ----------
def is_temp_file(path: Path, keywords: list, clf: TempFileClassifier) -> bool:
    """两级判定：关键词 或 ML 置信度"""
    name = path.name.lower()

    # ① 关键词快速过滤
    if any(kw.lower() in name for kw in keywords):
        return True

    # ② ML 判定
    p = clf.predict_proba(path)
    if p >= 0.8:            # 置信度高
        return True
    elif p <= 0.4:          # 置信度低
        return False
    else:
        # 中间区域进入人工确认
        print(f"\n⚖️ 对 {path} 置信度 {p:.2f}，需要人工确认：")
        choice = interactive_menu(["保留", "删除"])
        return choice == 1

# ---------- main 新增模型实例 ----------
def main(root: Path, keywords: list):
    if os.name=='nt' and not is_admin():
        print("需要管理员权限，正在以管理员身份重启...")
        relaunch_as_admin()

    # 加载模型
    clf = TempFileClassifier(root / 'temp_clf.pkl')

    logf = root.resolve() / LOG_FILENAME
    logger = setup_logger(logf)
    counters = {'scanned':0, 'deleted':0, 'errs':0}
    logger.info(f"开始清理：根目录={root.resolve()}")
    start = datetime.now()

    # 将 clf 传给清理函数
    clean_temp_files(root, keywords, logger, counters, clf)
    clean_incomplete_pairs(root, logger, counters)

    took = datetime.now() - start
    logger.info("=== 清理完成 ===")
    logger.info(f"总扫描文件: {counters['scanned']}")
    logger.info(f"总删除文件: {counters['deleted']}")
    logger.info(f"失败数: {counters['errs']}")
    logger.info(f"耗时: {took}")

# ---------- clean_temp_files 也需加参数 ----------
def clean_temp_files(root: Path, keywords: list, logger, counters: dict, clf: TempFileClassifier):
    script = Path(__file__).resolve()
    logf = root.resolve() / LOG_FILENAME
    for p in root.rglob('*'):
        if not p.is_file(): 
            continue
        if p.resolve() in (script, logf): 
            continue
        counters['scanned'] += 1
        if is_temp_file(p, keywords, clf):
            remove_file(p, logger, counters)
