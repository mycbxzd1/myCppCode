#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
基于文件路径字符 n‑gram 的轻量级分类器。
读取 labels.csv（path,is_temp），保存模型 temp_clf.pkl
"""

import csv
import pathlib
import joblib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline

DATA = pathlib.Path('labels.csv')
MODEL = pathlib.Path('temp_clf.pkl')

def load_samples():
    X, y = [], []
    if not DATA.exists():
        print("labels.csv 不存在，先创建一个并填充数据后再训练。")
        return X, y
    with DATA.open(encoding='utf-8') as f:
        for row in csv.reader(f):
            if len(row) != 2:
                continue
            path, label = row
            X.append(path)
            y.append(int(label))
    return X, y

def train():
    X, y = load_samples()
    if not X:
        return
    pipe = Pipeline([
        ('tfidf', TfidfVectorizer(
            analyzer='char', ngram_range=(1,4),
            lowercase=True, min_df=1, max_df=0.95)),
        ('clf', LogisticRegression(
            C=5.0, max_iter=1000, n_jobs=4))
    ])
    pipe.fit(X, y)
    joblib.dump(pipe, MODEL)
    print(f"模型已保存: {MODEL}")

if __name__ == '__main__':
    train()
