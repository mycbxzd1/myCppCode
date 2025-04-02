#include <bits/stdc++.h>
using namespace std;
const int N = 15, M = 95;
int dp[N][M][M][M], a[N], len;
int dfs(int dep, int sum, int num, int mod, bool lim)
{
    if (!dep)
        return (sum == mod && !num);
    if (!lim && ~dp[dep][sum][num][mod])
        return dp[dep][sum][num][mod];
    int res = 0, up = lim ? a[dep] : 9;
    for (int i = 0; i <= up; ++i)
        if (sum + i <= mod)
            res += dfs(dep - 1, sum + i, ((num << 3) + (num << 1) + i) % mod, mod, lim & (i == a[dep]));
    if (!lim)
        dp[dep][sum][num][mod] = res;
    return res;
}
int l, r;
int main()
{
    auto solve = [](int n)
    {len = 0;for (int i = n; i; i /= 10)a[++len] = i % 10;int res = 0;for (int i = 9 * len; i; --i)res += dfs(len, 0, 0, i, 1);return res; };
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    while (cin >> l >> r)
        cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}
