#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005; // 最大网格大小
int A[MAXN][MAXN]; // 保存修建隧道到达每个格子的花费
int dp[MAXN][MAXN]; // dp[i][j] 表示从起点到达格子 (i, j) 的最小花费

int main() {
    int W, H, C;
    cin >> W >> H >> C;
    
    // 输入修建隧道到达每个格子的花费
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            cin >> A[i][j];
        }
    }
    
    // 初始化 dp 数组为一个足够大的值
    for (int i = 0; i <= W; ++i) {
        fill(dp[i], dp[i] + MAXN, 1e9);
    }
    
    // 初始化起点 (1, 1) 的最小花费
    dp[1][1] = A[1][1];
    
    // 动态规划计算每个格子的最小花费
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            // 从上方格子移动过来
            if (i > 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + C);
            // 从左方格子移动过来
            if (j > 1)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + C);
            // 更新到达格子 (i, j) 的最小花费
            dp[i][j] += A[i][j];
        }
    }
    
    // 输出到达终点 (W, H) 的最小花费
    cout << dp[W][H] << endl;
    
    return 0;
}

