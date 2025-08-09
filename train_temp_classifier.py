#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
用文件路径字符 n‑gram 训练轻量级二分类模型。
读取 labels.csv（格式：path,is_temp），输出 temp_clf.pkl
依赖：scikit-learn, joblib
"""

from pathlib import Path
import csv
import joblib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline

DATA_FILE = Path('labels.csv')
MODEL_FILE = Path('temp_clf.pkl')


def load_samples():
    """读取标注数据"""
    X, y = [], []
    if not DATA_FILE.exists():
        print("⚠️  labels.csv 不存在，先创建后再训练。")
        return X, y
    with DATA_FILE.open(encoding='utf-8') as f:
        for row in csv.reader(f):
            if len(row) != 2:
                continue
            path, label = row
            X.append(path.strip())
            y.append(int(label.strip()))
    return X, y


def train():
    X, y = load_samples()
    if not X:
        return
    pipe = Pipeline([
        ('tfidf', TfidfVectorizer(
            analyzer='char', ngram_range=(1, 4),
            lowercase=True, min_df=1, max_df=0.95)),
        ('clf', LogisticRegression(
            C=5.0, max_iter=1000, n_jobs=4))
    ])
    pipe.fit(X, y)
    joblib.dump(pipe, MODEL_FILE)
    print(f"✅  模型已保存: {MODEL_FILE}")


if __name__ == '__main__':
    train()
