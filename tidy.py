#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
OI/ICPC 代码库自动分类脚本
在 E:\\myCppCode 目录下运行：
    python classify.py
生成：
    ./classification.json
    ./classification.csv
    ./summary.md
"""

from pathlib import Path
import re
import json
import csv
from collections import defaultdict, Counter
from datetime import datetime

# ---------- 规则定义区 ----------
# 1) 平台/来源目录关键词（优先从路径最前层判断）
ORIGIN_DIR_MAP = {
    r'(^|\\)acwing(\\|$)': 'AcWing',
    r'(^|\\)luogu(\\|$)': 'Luogu',
    r'(^|\\)CCF(\\|$)': 'CCF',
    r'(^|\\)hydro-system(\\|$)': 'HydroSystem',
    r'(^|\\)other-system(\\|$)': 'OtherSystem',
    r'(^|\\)template(\\|$)': 'Template',
    r'(^|\\)exui(\\|$)': 'ExUI',
    r'(^|\\)\.vscode(\\|$)': 'IDE',
    r'(^|\\)\.idea(\\|$)': 'IDE',
}

# 2) 子来源或子平台（更细的分类，匹配完整路径）
SUB_ORIGIN_DIR_MAP = {
    r'(^|\\)hydro-system(\\|$).*?(\\|^)hydro(\\|$)':          'Hydro-main',
    r'(^|\\)hydro-system(\\|$).*?(\\|^)kedaoi(\\|$)':         'KedaOI',
    r'(^|\\)hydro-system(\\|$).*?(\\|^)zzszoi(\\|$)':         'ZZSZOI',
    r'(^|\\)other-system(\\|$).*?(\\|^)nowcoder(\\|$)':       'Nowcoder',
    r'(^|\\)other-system(\\|$).*?(\\|^)xmoj(\\|$)':           'XMOJ',
    r'(^|\\)other-system(\\|$).*?(\\|^)oier\.team(\\|$)':     'OIER.team',
    r'(^|\\)other-system(\\|$).*?(\\|^)OI-民间联盟(\\|$)':      'OI民间联盟',
    r'(^|\\)other-system(\\|$).*?(\\|^)mna\.wang(\\|$)':      'mna.wang',
    r'(^|\\)other-system(\\|$).*?(\\|^)上海计算机学会(\\|$)':    'SCS_shanghai',
    r'(^|\\)other-system(\\|$).*?(\\|^)有道小图灵(\\|$)':        'Youdao-XTL',
    r'(^|\\)other-system(\\|$).*?(\\|^)核桃Oj(\\|$)':          'HetoOJ',
}

# 3) 正式赛事/模拟赛类型关键字
CONTEST_KEYWORDS = {
    'official':  [r'CSP', r'NOIP', r'CCF', r'BCSP', r'NOI', r'省选'],  # 正式/官方/省选
    'mock':      [r'模拟赛', r'全真模拟', r'押题', r'月赛', r'Round', r'Div', r'训练营'],
    'template':  [r'模板', r'template', r'newcirculation', r'exlucas', r'IO\.cpp'],
    'project':   [r'\.sln$', r'\.vcxproj$', r'\.iml$', r'\.xml$', r'\.json$', r'\.ps1$', r'Exui'],
}

# 4) 主题/算法标签关键字（中文 & 英文）
TOPIC_KEYWORDS = {
    'HLD':         [r'树链剖分', r'重链剖分'],
    'BalancedTree':[r'平衡树', r'营业额统计'],
    'BitmaskDP':   [r'状压dp', r'Hamilton'],
    'Math':        [r'math', r'线性代数', r'矩阵', r'组合数', r'lucas', r'Math', r'数学'],
    'String':      [r'回文', r'string', r'子串', r'KMP', r'AC自动机'],
    'Graph':       [r'桥', r'桥 (bridge)', r'graph', r'gap', r'城市道路', r'countpath'],
    'DP':          [r'dp', r'DP', r'动态规划'],
    'SegmentTree': [r'线段树', r'segment', r'点分治'],
    'Flow':        [r'最大流', r'费用流', r'flow'],
}

# 5) 问题 ID 正则（可扩展）
PATTERN_PROBLEM_ID = [
    (r'P(\d{3,6})', 'Luogu'),      # Pxxxx
    (r'T(\d{1,4})', 'GenericT'),   # Tn
    (r'E0?\d{3,4}', 'E'),          # E00xx
    (r'\[BCSP\d{4}\]', 'BCSP'),    # [BCSP2024]
]

# 6) 文件类型识别
EXT_TYPE_MAP = {
    '.cpp': 'source',
    '.c':   'source',
    '.h':   'header',
    '.hpp': 'header',
    '.py':  'source',
    '.ps1': 'script',
    '.ts':  'test_ts',
    '.in':  'test_in',
    '.out': 'test_out',
    '.exe': 'binary',
    '.sln': 'ide_project',
    '.vcxproj': 'ide_project',
    '.filters': 'ide_project',
    '.user': 'ide_project',
    '.iml':  'ide_project',
    '.xml':  'config',
    '.json': 'config',
    '.md':   'doc',
    '.txt':  'text',
    '.sk':   'ui_skin',
}

# ---------- 工具函数 ----------
def match_first(patterns, text, flags=re.IGNORECASE):
    """返回第一个匹配的正则（字符串列表），否则 None"""
    for pat in patterns:
        if re.search(pat, text, flags):
            return pat
    return None

def detect_origin(path_str):
    for pat, name in SUB_ORIGIN_DIR_MAP.items():
        if re.search(pat, path_str, re.IGNORECASE):
            return name
    for pat, name in ORIGIN_DIR_MAP.items():
        if re.search(pat, path_str, re.IGNORECASE):
            return name
    return 'Unknown'

def detect_contest_type(path_str, file_name):
    full = path_str + '\\' + file_name
    # template优先级高
    if match_first(CONTEST_KEYWORDS['template'], full):
        return 'template'
    if match_first(CONTEST_KEYWORDS['official'], full):
        return 'official'
    if match_first(CONTEST_KEYWORDS['mock'], full):
        return 'mock'
    # project 放后面以免覆盖 official/mock
    if match_first(CONTEST_KEYWORDS['project'], full):
        return 'project'
    return 'normal'

def detect_topics(path_str, file_name):
    full = path_str + '\\' + file_name
    tags = set()
    for tag, pats in TOPIC_KEYWORDS.items():
        if match_first(pats, full):
            tags.add(tag)
    return sorted(tags)

def detect_problem_ids(file_name):
    ids = []
    for pat, source in PATTERN_PROBLEM_ID:
        m = re.search(pat, file_name, re.IGNORECASE)
        if m:
            ids.append({'id': m.group(0), 'source': source})
    return ids

def detect_artifact_type(suffix, file_name):
    t = EXT_TYPE_MAP.get(suffix.lower())
    if t:
        return t
    # fallback by name
    name = file_name.lower()
    if name.endswith('.in'):
        return 'test_in'
    if name.endswith('.out'):
        return 'test_out'
    return 'other'

# ---------- 主流程 ----------
def main():
    root = Path('.').resolve()
    files_info = []
    for p in root.rglob('*'):
        if p.is_dir():
            continue
        rel = p.relative_to(root)
        rel_str = str(rel)
        path_str = str(rel.parent)
        file_name = p.name
        suffix = p.suffix

        origin = detect_origin(rel_str)
        contest_type = detect_contest_type(path_str, file_name)
        topics = detect_topics(path_str, file_name)
        prob_ids = detect_problem_ids(file_name)
        artifact_type = detect_artifact_type(suffix, file_name)

        files_info.append({
            'rel_path': rel_str.replace('\\', '/'),
            'origin': origin,
            'contest_type': contest_type,
            'artifact_type': artifact_type,
            'topics': topics,
            'problem_ids': prob_ids,
            'size': p.stat().st_size,
            'mtime': datetime.fromtimestamp(p.stat().st_mtime).isoformat(timespec='seconds'),
        })

    # 输出 JSON
    with open('classification.json', 'w', encoding='utf-8') as f:
        json.dump(files_info, f, ensure_ascii=False, indent=2)

    # 输出 CSV
    csv_cols = ['rel_path', 'origin', 'contest_type', 'artifact_type', 'topics', 'problem_ids', 'size', 'mtime']
    with open('classification.csv', 'w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=csv_cols)
        writer.writeheader()
        for item in files_info:
            row = item.copy()
            row['topics'] = ';'.join(item['topics'])
            row['problem_ids'] = ';'.join([d['id'] for d in item['problem_ids']])
            writer.writerow(row)

    # 汇总统计 & summary.md
    cnt_origin = Counter([d['origin'] for d in files_info])
    cnt_contest = Counter([d['contest_type'] for d in files_info])
    cnt_artifact = Counter([d['artifact_type'] for d in files_info])

    topic_counter = Counter()
    for d in files_info:
        topic_counter.update(d['topics'])

    # 生成层级结构：origin -> (contest_type) -> files
    tree = defaultdict(lambda: defaultdict(list))
    for d in files_info:
        tree[d['origin']][d['contest_type']].append(d)

    with open('summary.md', 'w', encoding='utf-8') as f:
        f.write('# Classification Summary\n\n')
        f.write(f'Generated at: {datetime.now().isoformat(timespec="seconds")}\n\n')

        f.write('## Overall Statistics\n\n')
        f.write(f'- Total files: **{len(files_info)}**\n')
        f.write('### By Origin\n')
        for k, v in cnt_origin.most_common():
            f.write(f'- {k}: {v}\n')
        f.write('\n### By Contest Type\n')
        for k, v in cnt_contest.most_common():
            f.write(f'- {k}: {v}\n')
        f.write('\n### By Artifact Type\n')
        for k, v in cnt_artifact.most_common():
            f.write(f'- {k}: {v}\n')
        f.write('\n### Topic Tags Frequency\n')
        for k, v in topic_counter.most_common():
            f.write(f'- {k}: {v}\n')
        f.write('\n---\n')

        # 详细列表
        for origin, cdict in tree.items():
            f.write(f'## Origin: {origin}\n\n')
            for ctype, flist in sorted(cdict.items()):
                f.write(f'### Contest Type: {ctype}  (files: {len(flist)})\n\n')
                for d in sorted(flist, key=lambda x: x['rel_path']):
                    pid_str = ','.join([i["id"] for i in d['problem_ids']]) if d['problem_ids'] else ''
                    topics_str = ','.join(d['topics'])
                    f.write(f'- `{d["rel_path"]}` | {d["artifact_type"]} | IDs[{pid_str}] | Tags[{topics_str}]\n')
                f.write('\n')
            f.write('\n')

    # 控制台输出部分统计
    print('=== Classification Done ===')
    print(f'Total files: {len(files_info)}')
    print('By Origin:', dict(cnt_origin))
    print('By Contest Type:', dict(cnt_contest))
    print('By Artifact Type:', dict(cnt_artifact))
    print('Top Topics:', topic_counter.most_common(10))
    print('-> classification.json / classification.csv / summary.md generated.')

if __name__ == '__main__':
    main()
