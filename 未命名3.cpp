#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    int sum1 = 0, sum2 = 0;
    vector<int> zeroItems;

    // 输入物品的价值和标记
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (b[i] == 1) {
            sum1 += a[i]; // 标记为1的物品加到sum1
        } else if (b[i] == 2) {
            sum2 += a[i]; // 标记为2的物品加到sum2
        } else {
            zeroItems.push_back(a[i]); // 标记为0的物品放入待选项
        }
    }

    int total = accumulate(zeroItems.begin(), zeroItems.end(), 0);
    int target = abs(sum1 - sum2);
    int offset = total;
    vector<bool> dp(2 * offset + 1, false);
    dp[offset] = true; // 初始状态，差为0

    for (int x : zeroItems) {
        vector<bool> new_dp = dp;
        for (int i = 0; i <= 2 * offset; ++i) {
            if (dp[i]) {
                if (i + x <= 2 * offset) new_dp[i + x] = true;
                if (i - x >= 0) new_dp[i - x] = true;
            }
        }
        dp = new_dp;
    }

    int min_diff = abs(sum1 - sum2);
    for (int i = 0; i <= 2 * offset; ++i) {
        if (dp[i]) {
            int candidate_diff = abs((sum1 + (i - offset)) - (sum2 + (total - (i - offset))));
            min_diff = min(min_diff, candidate_diff);
        }
    }

    cout << min_diff << endl;
    return 0;
}

