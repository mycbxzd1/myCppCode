#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250000 + 5;
int n;
vector<int> siz, zeros, colsiz, memfa, co, colfa;
vector<vector<pair<int, int>>> adj;
long long ans = 0;
void dfs1(int u = 1, int parent = 0)
{
    siz[u] = 1;
    for (const auto &[v, w] : adj[u])
    {
        if (v == parent)
            continue;
        co[v] = w;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}
void dfs2(int u = 1, int parent = 0)
{
    colsiz[u] = siz[u];
    int prev = memfa[co[u]];
    colfa[u] = prev;
    memfa[co[u]] = u;
    for (const auto &[v, w] : adj[u])
    {
        if (v == parent)
            continue;
        dfs2(v, u);
    }
    memfa[co[u]] = prev;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    adj.assign(n + 1, {});
    siz.assign(n + 1, 0);
    zeros.assign(n + 1, n);
    colsiz.assign(n + 1, 0);
    memfa.assign(n + 1, 0);
    co.assign(n + 1, 0);
    colfa.assign(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs1();
    dfs2();
    for (int i = 1; i <= n; ++i)
    {
        if (colfa[i])
            colsiz[colfa[i]] -= siz[i];
        else
            zeros[co[i]] -= siz[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        if (colfa[i])
            ans += 1LL * colsiz[i] * colsiz[colfa[i]];
        else
            ans += 1LL * colsiz[i] * zeros[co[i]];
    }
    cout << ans << "\n";
    return 0;
}
