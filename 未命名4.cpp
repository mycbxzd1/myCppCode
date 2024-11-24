#include<bits/stdc++.h>
using namespace std;

const int N = 105;  // 最大物品数量
int f[N][2];  // 状态定义：f[i][0] 表示物品 a[i] 分配给 sum1 的最小 abs(sum1 - sum2)，f[i][1] 表示物品 a[i] 分配给 sum2 的最小 abs(sum1 - sum2)

int main() {
    int n;  // 物品数量
    cin >> n;

    int a[N], b[N];  // a[] 存储每个物品的价值，b[] 存储每个物品的标记
    int sum1 = 0, sum2 = 0;  // sum1 表示标记为 1 的物品的和，sum2 表示标记为 2 的物品的和

    // 读入物品的价值和标记
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (b[i] == 1) sum1 += a[i];  // 标记为 1 的物品加入 sum1
        if (b[i] == 2) sum2 += a[i];  // 标记为 2 的物品加入 sum2
    }

    // 初始化
    f[0][0] = f[0][1] = abs(sum1 - sum2);  // 初始时只考虑固定加入 sum1 和 sum2 的物品

    // 动态规划，处理标记为 0 的物品
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {  // 只有标记为 0 的物品可以自由分配
            f[i + 1][0] = min(f[i][0] + a[i], f[i][1] - a[i]);  // 分配给 sum1
            f[i + 1][1] = min(f[i][1] + a[i], f[i][0] - a[i]);  // 分配给 sum2
        } else {  // 标记为 1 或 2 的物品已固定分配
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = f[i][1];
        }
    }

    // 取最小值输出结果
    cout << min(f[n][0], f[n][1]) << endl;

    return 0;
}

