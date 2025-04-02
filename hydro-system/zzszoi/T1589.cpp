#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int dp[10][2], sw[10];
int dfs(int pos, int pd, bool flag)
{
    if (pos == -1)
        return 1;
    if (!flag && ~dp[pos][pd])
        return dp[pos][pd];
    int len = flag ? sw[pos] : 9, ans = 0;
    for (int i = 0; i <= len; i++)
    {
        if (i == 4 || (pd && i == 2))
            continue;
        ans += dfs(pos - 1, i == 6, flag && i == len);
    }
    if (!flag)
        dp[pos][pd] = ans;
    return ans;
}

int n, m;
int main()
{
    auto solve = [](int x)
    {int len=0;while(x)sw[len++]=x%10,x/=10;return dfs(len-1,0,1); };
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    while (cin >> n >> m && (n || m))
        cout << solve(m) - solve(n - 1) << '\n';
    return 0;
}
