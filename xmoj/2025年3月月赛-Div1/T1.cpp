#include <bits/stdc++.h>
using namespace std;
int f[50][50];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> f[i][j];
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int pop_count = __builtin_popcount(mask);
        if (pop_count % 2 != 0)
            continue;
        for (int i = 0; i < n; ++i)
        {
            if ((mask & (1 << i)) == 0)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if ((mask & (1 << j)) == 0)
                    {
                        int next_mask = mask | (1 << i) | (1 << j);
                        dp[next_mask] = max(dp[next_mask], dp[mask] + f[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
