#include <iostream>
#include <algorithm>
using namespace std;

const int N = 130;
int skill[9];
int cd[4];
int ult;
int dp[N][N][N][2]; // dp数组

int main() {
    // 读入技能数据
    for (int i = 0; i < 9; i++) cin >> skill[i];
    cin >> ult; // 终极技伤害
    for (int i = 0; i < 4; i++) cin >> cd[i]; // 4个技能的冷却时间

    // 状态转移
    for (int q = 0; q <= cd[0]; q++) {
        for (int w = 0; w <= cd[1]; w++) {
            for (int e = 0; e <= cd[2]; e++) {
                for (int ready = 0; ready <= 1; ready++) {
                    // 技能1：如果冷却时间允许，更新dp状态
                    if (q + 1 <= cd[0]) {
                        dp[q+1][w][e][ready] = max(dp[q+1][w][e][ready], dp[q][w][e][ready] + skill[0]);
                    }

                    // 技能2、3：根据冷却时间更新dp状态
                    if (q + 1 <= cd[0] && w + 1 <= cd[1]) {
                        dp[q+1][w+1][e][ready] = max(dp[q+1][w+1][e][ready], dp[q][w][e][ready] + skill[1]);
                        dp[q+1][w+1][e][ready] = max(dp[q+1][w+1][e][ready], dp[q][w][e][ready] + skill[2]);
                    }

                    // 技能4：单独判断冷却时间
                    if (w + 1 <= cd[1] && q + 1 <= cd[0]) {
                        dp[q][w+1][e][ready] = max(dp[q][w+1][e][ready], dp[q][w][e][ready] + skill[3]);
                    }

                    // 技能5：冷却时间为2
                    if (w + 2 <= cd[1]) {
                        dp[q][w+2][e][ready] = max(dp[q][w+2][e][ready], dp[q][w][e][ready] + skill[4]);
                    }

                    // 技能6：跨冷却时间1、2判断
                    if (w + 1 <= cd[1] && e + 1 <= cd[2]) {
                        dp[q][w+1][e+1][ready] = max(dp[q][w+1][e+1][ready], dp[q][w][e][ready] + skill[5]);
                    }

                    // 技能7、8：更新状态
                    if (e + 1 <= cd[2] && q + 1 <= cd[0]) {
                        dp[q+1][w][e+1][ready] = max(dp[q+1][w][e+1][ready], dp[q][w][e][ready] + skill[6]);
                    }

                    if (e + 1 <= cd[2] && w + 1 <= cd[1]) {
                        dp[q][w+1][e+1][ready] = max(dp[q][w+1][e+1][ready], dp[q][w][e][ready] + skill[7]);
                    }

                    // 技能9：冷却时间为2
                    if (e + 2 <= cd[2]) {
                        dp[q][w][e+2][ready] = max(dp[q][w][e+2][ready], dp[q][w][e][ready] + skill[8]);
                    }

                    // 使用终极技的状态转移
                    if (ready == 1) {
                        dp[q][w][e][0] = max(dp[q][w][e][0], dp[q][w][e][1]); // 终极技已使用，恢复冷却
                    } else {
                        dp[q][w][e][1] = max(dp[q][w][e][1], dp[q][w][e][0] + ult); // 未使用终极技时，使用终极技
                    }
                }
            }
        }
    }

    // 计算最大值
    int ans = 0;
    for (int q = 0; q <= cd[0]; q++) {
        for (int w = 0; w <= cd[1]; w++) {
            for (int e = 0; e <= cd[2]; e++) {
                ans = max(ans, dp[q][w][e][0]);
                ans = max(ans, dp[q][w][e][1]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

