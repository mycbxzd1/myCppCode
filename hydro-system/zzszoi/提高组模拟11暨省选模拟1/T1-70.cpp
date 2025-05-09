#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int n, q, k;
vector<vector<int>> adj;
vector<ll> m, w;
vector<int> dis;
vector<array<array<ll, 2>, 2>> dp;
void dfs(int u, int p, int L)
{
    for (int v : adj[u])
        if (v != p)
            dfs(v, u, L);
    ll sum_if_base = 0;
    ll sum_max0 = 0;
    ll max_gain = -INF;

    for (int v : adj[u])
        if (v != p)
        {
            ll best_c1 = max(dp[v][1][0], dp[v][1][1]);
            sum_if_base += best_c1;
            ll best_c0 = max(dp[v][0][0], dp[v][0][1]);
            sum_max0 += best_c0;
            ll sacrifice = dp[v][0][1] - best_c0;
            max_gain = max(max_gain, sacrifice);
        }
    dp[u][0][1] = dp[u][1][1] = sum_if_base;
    for (int c = 0; c <= 1; c++)
    {
        ll best = m[u] + sum_max0;
        ll gather;
        if (c == 1 || dis[u] <= L)
            gather = w[u] + sum_max0;
        else
        {
            if (max_gain <= -INF / 2)
                gather = -INF;
            else
                gather = w[u] + sum_max0 + max_gain;
        }
        best = max(best, gather);
        dp[u][c][0] = best;
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    m.resize(n + 1);
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cin >> k;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis.assign(n + 1, -1);
    queue<int> que;
    dis[k] = 0;
    que.push(k);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : adj[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    dp.assign(n + 1, {{{0, 0}, {0, 0}}});
    while (q--)
    {
        int L;
        cin >> L;
        dfs(k, 0, L);
        ll ans = max(dp[k][0][0], dp[k][0][1]);
        cout << ans << "\n";
    }
    return 0;
}
