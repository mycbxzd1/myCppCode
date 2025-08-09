#include <bits/stdc++.h>
using namespace std;
const bool isdebug = 1;
const string filename = "network";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!isdebug)
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }

    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    g.reserve(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> a(k);
    vector<char> isSpec(n + 1, 0);
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        isSpec[a[i]] = 1;
    }

    vector<pair<int, int>> edges;
    edges.reserve(n - 1);

    auto bfs = [&](int root)
    {
        vector<char> vis(n + 1, 0);
        queue<int> q;
        vis[root] = 1;
        q.push(root);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    edges.emplace_back(u, v);
                    q.push(v);
                }
            }
        }
    };
    if (k == 0)
    {
        bfs(1);
        if ((int)edges.size() != n - 1)
        {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n"
             << 1 << "\n";
        for (auto &e : edges)
            cout << e.first << " " << e.second << "\n";
        return 0;
    }
    if (k == 1)
    {
        int x = a[0];
        bfs(x);
        if ((int)edges.size() != n - 1)
        {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n"
             << x << "\n";
        for (auto &e : edges)
            cout << e.first << " " << e.second << "\n";
        return 0;
    }
    vector<int> comp(n + 1, -1);
    vector<int> comp_rep;
    comp_rep.reserve(n);
    int compCnt = 0;
    {
        vector<char> vis(n + 1, 0);
        queue<int> q;
        for (int u = 1; u <= n; ++u)
        {
            if (isSpec[u] || vis[u])
                continue;
            comp_rep.push_back(u);
            comp[u] = compCnt;
            vis[u] = 1;
            q.push(u);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int y : g[x])
                {
                    if (!isSpec[y] && !vis[y])
                    {
                        vis[y] = 1;
                        comp[y] = compCnt;
                        edges.emplace_back(x, y);
                        q.push(y);
                    }
                }
            }
            ++compCnt;
        }
    }
    if (compCnt == 0)
    {
        cout << "NO\n";
        return 0;
    }
    vector<int> cnt(compCnt, 0);
    vector<int> mark(compCnt, 0);
    int stamp = 1;
    for (int s : a)
    {
        ++stamp;
        for (int v : g[s])
        {
            if (isSpec[v])
                continue;
            int c = comp[v];
            if (mark[c] != stamp)
            {
                mark[c] = stamp;
                ++cnt[c];
            }
        }
    }
    int Cstar = -1;
    for (int c = 0; c < compCnt; ++c)
    {
        if (cnt[c] == k)
        {
            Cstar = c;
            break;
        }
    }
    if (Cstar == -1)
    {
        cout << "NO\n";
        return 0;
    }
    int x = comp_rep[Cstar];
    for (int s : a)
    {
        bool ok = false;
        for (int v : g[s])
        {
            if (!isSpec[v] && comp[v] == Cstar)
            {
                edges.emplace_back(s, v);
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            cout << "NO\n";
            return 0;
        }
    }
    vector<char> attached(compCnt, 0);
    attached[Cstar] = 1;
    vector<pair<int, int>> oneEdge(compCnt, {-1, -1});
    for (int s : a)
    {
        for (int v : g[s])
        {
            if (isSpec[v])
                continue;
            int c = comp[v];
            if (c != Cstar && !attached[c])
            {
                attached[c] = 1;
                oneEdge[c] = {s, v};
            }
        }
    }
    for (int c = 0; c < compCnt; ++c)
    {
        if (c == Cstar)
            continue;
        if (!attached[c])
        {
            cout << "NO\n";
            return 0;
        }
        edges.emplace_back(oneEdge[c].first, oneEdge[c].second);
    }
    if ((int)edges.size() != n - 1)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n"
         << x << "\n";
    for (auto &e : edges)
        cout << e.first << " " << e.second << "\n";
    return 0;
}
