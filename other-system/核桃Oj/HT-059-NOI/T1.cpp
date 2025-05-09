/*#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int addmod(int a, int b)
{
    int s = a + b;
    return s >= mod ? s - mod : s;
}
int mulmod(int a, int b)
{
    return (a * b % mod);
}
int n;
vector<vector<int>> G;
vector<int> color, roots, MP, MC, NU;
vector<vector<int>> blkCh;

void dfs_build(int u, int fa, vector<int> &stk)
{
    if (color[u])
    {
        if (!stk.empty())
            blkCh[stk.back()].push_back(u);
        else
            roots.push_back(u);
        stk.push_back(u);
    }
    for (int v : G[u])
    {
        if (v == fa)
            continue;
        dfs_build(v, u, stk);
    }
    if (color[u])
        stk.pop_back();
}
void dfs_dp(int u)
{
    for (int v : blkCh[u])
        dfs_dp(v);

    if (blkCh[u].empty())
    {
        MP[u] = 1;
        MC[u] = 0;
        NU[u] = 1;
        return;
    }
    int k = blkCh[u].size();
    vector<int> pre(k + 1, 1), suf(k + 1, 1);
    for (int i = 0; i < k; i++)
    {
        int v = blkCh[u][i];
        pre[i + 1] = mulmod(pre[i], addmod(MC[v], NU[v]));
    }
    for (int i = k - 1; i >= 0; i--)
    {
        int v = blkCh[u][i];
        suf[i] = mulmod(suf[i + 1], addmod(MC[v], NU[v]));
    }
    MP[u] = pre[k];
    int prodMC = 1;
    for (int v : blkCh[u])
        prodMC = mulmod(prodMC, MC[v]);
    NU[u] = prodMC;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int v = blkCh[u][i];
        int others = mulmod(pre[i], suf[i + 1]);
        sum = addmod(sum, mulmod(MP[v], others));
    }
    MC[u] = sum;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        color.assign(n, 0);
        for (int i = 0; i < n; i++)
            cin >> color[i];
        G.assign(n, {});
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        blkCh.assign(n, {});
        roots.clear();
        vector<int> stk;
        dfs_build(0, -1, stk);
        MP.assign(n, 0);
        MC.assign(n, 0);
        NU.assign(n, 0);
        for (int r : roots)
            dfs_dp(r);
        int ans = 1;
        for (int r : roots)
            ans = mulmod(ans, addmod(MC[r], NU[r]));
        cout << ans << "\n";
    }
    return 0;
}*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n, -1), depth(n, 0), tin(n), tout(n);
        int timer = 0;
        function<void(int, int)> dfs = [&](int u, int p)
        {
            tin[u] = timer++;
            parent[u] = p;
            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
            tout[u] = timer - 1;
        };
        dfs(0, -1);

        auto is_ancestor = [&](int u, int v)
        {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };
        vector<vector<int>> path_mask(n, vector<int>(n, 0));
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (u == v)
                    continue;
                if (is_ancestor(u, v) || is_ancestor(v, u))
                {
                    int mask = 0;
                    int x = u;
                    mask |= (1 << x);
                    while (x != v)
                    {
                        x = parent[x];
                        mask |= (1 << x);
                    }
                    x = v;
                    mask |= (1 << x);
                    while (x != u)
                    {
                        x = parent[x];
                        mask |= (1 << x);
                    }
                    path_mask[u][v] = mask;
                }
            }
        }
        int init_mask = 0;
        for (int i = 0; i < n; i++)
            if (c[i] == 1)
                init_mask |= (1 << i);
        unordered_set<int> visited;
        unordered_set<int> finals;
        queue<int> q;
        visited.insert(init_mask);
        q.push(init_mask);
        while (!q.empty())
        {
            int mask = q.front();
            q.pop();

            bool moved = false;
            vector<int> blacks;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    blacks.push_back(i);
            int bsz = blacks.size();
            for (int i = 0; i < bsz; i++)
                for (int j = i + 1; j < bsz; j++)
                {
                    int u = blacks[i], v = blacks[j];
                    if (is_ancestor(u, v) || is_ancestor(v, u))
                    {
                        int pm = path_mask[u][v] & mask;
                        if ((pm & ~((1 << u) | (1 << v))) == 0)
                        {
                            int new_mask = mask & ~(1 << u) & ~(1 << v);
                            if (!visited.count(new_mask))
                            {
                                visited.insert(new_mask);
                                q.push(new_mask);
                            }
                            moved = true;
                        }
                    }
                }
            if (!moved)
                finals.insert(mask);
        }
        int answer = (int)finals.size() % mod;
        cout << answer << "\n";
    }
    return 0;
}
