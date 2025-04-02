#include <bits/stdc++.h>
using namespace std;
const int N = 1101 * 50 + 10;
const int M = (N + 1100 + 20 * 1101) + 10;
const int INF = 100000000;
int n, m, k, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];
struct Ship
{
    int h, r;
    int id[30];
} ships[30];
int p[1200];
bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0;
    cur[S] = h[S];
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T)
                    return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}
int dfs_flow(int u, int limit)
{
    if (u == T)
        return limit;
    int flow = 0;
    for (int i = cur[u]; i != -1 && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = dfs_flow(ver, min(f[i], limit - flow));
            if (!t)
                d[ver] = -1;
            f[i] -= t;
            f[i ^ 1] += t;
            flow += t;
        }
    }
    return flow;
}
int dinic()
{
    int r = 0, flow;
    while (bfs())
    {
        for (int i = 0; i < N; i++)
            cur[i] = h[i];
        while ((flow = dfs_flow(S, INF)) != 0)
            r += flow;
    }
    return r;
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
    auto get = [](int i, int day)
    { return day * (n + 2) + i; };
    auto add = [](int a, int b, int c)
    {e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++; };

    cin >> n >> m >> k;
    S = N - 2, T = N - 1;
    memset(h, -1, sizeof(h));
    for (int i = 0; i <= n + 1; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ships[i].h = a;
        ships[i].r = b;
        for (int j = 0; j < b; j++)
        {
            int id;
            cin >> id;
            if (id == -1)
                id = n + 1;
            ships[i].id[j] = id;
            if (j > 0)
            {
                int x = ships[i].id[j - 1];
                p[find(x)] = find(id);
            }
        }
    }
    if (find(0) != find(n + 1))
        cout << 0 << "\n";
    else
    {
        add(S, get(0, 0), k);
        add(get(n + 1, 0), T, INF);
        int day = 1, res = 0;
        while (true)
        {
            add(get(n + 1, day), T, INF);
            for (int i = 0; i <= n + 1; i++)
                add(get(i, day - 1), get(i, day), INF);
            for (int i = 0; i < m; i++)
            {
                int r = ships[i].r;
                int a = ships[i].id[(day - 1) % r];
                int b = ships[i].id[day % r];
                add(get(a, day - 1), get(b, day), ships[i].h);
            }
            res += dinic();
            if (res >= k)
                break;
            day++;
        }
        cout << day << "\n";
    }

    return 0;
}
