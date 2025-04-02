#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 4000;       // 偏移量，将可能的负差转为非负索引
const int NEG_INF = -1e9;        // 表示不可达状态

// 生成测试数据，要求候选人的 r 和 f 均在 [1,20] 范围内，但不允许 r == f
void generateTestCase(int id) {
    // 为保证不同测试点数据不同，使用 time(0) + id 作为随机种子
    srand((unsigned)time(0) + id);
    
    int N = rand() % 200 + 1;               // N 在 [1,200]
    int M = rand() % min(20, N) + 1;          // M 在 [1, min(20, N)]
    
    // 构造输入文件名 candidateid{id}.in
    char inFile[50];
    sprintf(inFile, "candidateid%d.in", id);
    ofstream fout(inFile);
    
    fout << N << " " << M << "\n";
    for (int i = 0; i < N; i++) {
        int r, f;
        // 反复生成直到 r 和 f 不相等，确保候选人两维数据有差异
        do {
            r = rand() % 20 + 1;
            f = rand() % 20 + 1;
        } while(r == f);
        fout << r << " " << f << "\n";
    }
    fout.close();
}

// 根据指定测试点的输入文件进行求解，并将结果写入对应输出文件
void solveTestCase(int id) {
    char inFile[50], outFile[50];
    sprintf(inFile, "candidateid%d.in", id);
    sprintf(outFile, "candidate%d.out", id);
    
    ifstream fin(inFile);
    ofstream fout(outFile);
    
    int N, M;
    fin >> N >> M;
    vector<pair<int,int>> candidates(N);
    for (int i = 0; i < N; i++){
        fin >> candidates[i].first >> candidates[i].second;
    }
    fin.close();
    
    // dp[j][s] 表示选 j 个候选人后（已偏移后 s），(r - f) 的累计差值对应的最大 (r + f) 总和
    vector<vector<int>> dp(M+1, vector<int>(OFFSET * 2 + 1, NEG_INF));
    dp[0][OFFSET] = 0; // 初始状态：选 0 个人时，差值为 0，总和为 0

    // 采用 0/1 背包思想更新状态
    for (auto [r, f] : candidates) {
        vector<vector<int>> new_dp = dp;  // 临时数组，避免重复使用同一候选人
        for (int j = M - 1; j >= 0; j--) {
            for (int s = 0; s <= OFFSET * 2; s++) {
                if (dp[j][s] != NEG_INF) {
                    int new_s = s + (r - f);
                    if (new_s >= 0 && new_s <= OFFSET * 2) {
                        new_dp[j+1][new_s] = max(new_dp[j+1][new_s], dp[j][s] + r + f);
                    }
                }
            }
        }
        dp.swap(new_dp);
    }
    
    // 在 dp[M][s] 中寻找 |s - OFFSET| 最小的（即两维总分差的绝对值最小），
    // 在这种情况下选出 (r+f) 总和最大的答案
    int min_diff = INT_MAX, max_sum = 0;
    for (int s = 0; s <= OFFSET * 2; s++) {
        if (dp[M][s] != NEG_INF) {
            int diff = abs(s - OFFSET);
            if (diff < min_diff) {
                min_diff = diff;
                max_sum = dp[M][s];
            } else if (diff == min_diff) {
                max_sum = max(max_sum, dp[M][s]);
            }
        }
    }
    
    fout << min_diff << "\n" << max_sum << "\n";
    fout.close();
}

int main() {
    // 一次生成 10 组测试数据文件，并对每组数据求解，生成对应输出文件
    for (int id = 1; id <= 10; id++) {
        generateTestCase(id);
        solveTestCase(id);
    }
    return 0;
}
