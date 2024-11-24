#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n + 1, 1e9); // dp数组初始化为一个较大的值
    dp[0] = 0; // 没有士兵时操作次数为0

    for (int i = 0; i < n; i++) {
        vector<int> cnt(n + 1, 0); // 记录当前段中每个战斗力的出现次数
        int maxFreq = 0; // 当前段中最多的相同战斗力的士兵数量
        for (int j = i; j < n; j++) {
            cnt[a[j]]++;
            maxFreq = max(maxFreq, cnt[a[j]]);
            dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            if (maxFreq > 1) {
                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}

