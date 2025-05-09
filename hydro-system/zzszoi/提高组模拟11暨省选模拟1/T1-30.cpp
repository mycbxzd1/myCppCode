#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, k, ans;
vector<vector<int>> adj;
vector<int> m, w, dis, state;
void dfs(int u, int L)
{
    if (u > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (state[i] == 0)
                sum += m[i];
            else if (state[i] == 1)
            {
                bool ok = (dis[i] <= L);
                if (!ok)
                {
                    for (int v : adj[i])
                    {
                        if (state[v] == 2)
                        {
                            ok = true;
                            break;
                        }
                    }
                }
                if (!ok)
                    return;
                sum += w[i];
            }
        }
        ans = max(ans, sum);
        return;
    }
    for (int t = 0; t < 3; t++)
    {
        state[u] = t;
        dfs(u + 1, L);
    }
}
signed main()
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
    state.assign(n + 1, 0);
    while (q--)
    {
        int L;
        cin >> L;
        ans = 0;
        dfs(1, L);
        cout << ans << "\n";
    }
    return 0;
}
