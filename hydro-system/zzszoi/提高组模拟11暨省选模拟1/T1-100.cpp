#include <bits/stdc++.h>
#define int long long
using namespace std;
int depth = 0;
vector<int> m, w;
vector<array<int, 4>> dp;
vector<int> f, sum;
vector<vector<int>> g;
void dfs(int u, int father = 0, int dep = 0)
{
    dp[u][0] = m[u];
    dp[u][1] = dp[u][2] = w[u];
    depth = max(depth, dep);
    int minn = numeric_limits<int>::max();
    bool flag = false;
    for (int v : g[u])
    {
        if (v == father)
            continue;
        dfs(v, u, dep + 1);
        dp[u][0] += max({dp[v][0], dp[v][1], dp[v][3]});
        if (dp[v][3] >= max(dp[v][0], dp[v][1]))
        {
            dp[u][1] += dp[v][3];
            flag = true;
        }
        else
        {
            dp[u][1] += max(dp[v][0], dp[v][1]);
            minn = min(minn, max(dp[v][0], dp[v][1]) - dp[v][3]);
        }
        dp[u][2] += max({dp[v][0], dp[v][1], dp[v][3]});
        dp[u][3] += max({dp[v][0], dp[v][1], dp[v][2], dp[v][3]});
    }
    f[dep] += max({dp[u][0], dp[u][3], dp[u][2]});
    sum[dep] += max(m[u], w[u]);
    if (!flag)
        dp[u][1] -= minn;
}

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q, k;
    cin >> n >> q;
    m.assign(n + 1, 0);
    w.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> m[i];
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    cin >> k;
    g.assign(n + 1, {});
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp.assign(n + 1, {0, 0, 0, 0});
    f.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    dfs(k);
    for (int i = 1; i <= n; ++i)
        sum[i] += sum[i - 1];
    while (q--)
    {
        int L;
        cin >> L;
        cout << f[L] + sum[L - 1] << '\n';
    }
    return 0;
}
