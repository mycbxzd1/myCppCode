#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 251010, INF = 100000000;

int n, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];
int g[N], w[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    f[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
    e[idx] = a;
    f[idx] = 0;
    ne[idx] = h[b];
    h[b] = idx++;
}

bool bfs()
{
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S;
    d[S] = 0;
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
        while ((flow = dfs_flow(S, INF)) > 0)
            r += flow;
    }
    return r;
}

int main()
{
    cin >> n;
    S = 0, T = n * 2 + 1;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        add(i, i + n, 1);
        g[i] = 1;
        for (int j = 1; j < i; j++)
            if (w[j] <= w[i])
                g[i] = max(g[i], g[j] + 1);
        for (int j = 1; j < i; j++)
            if (w[j] <= w[i] && g[j] + 1 == g[i])
                add(n + j, i, 1);
        s = max(s, g[i]);
        if (g[i] == 1)
            add(S, i, 1);
    }
    for (int i = 1; i <= n; i++)
        if (g[i] == s)
            add(n + i, T, 1);

    cout << s << "\n";

    if (s == 1)
        cout << n << "\n"
             << n << "\n";
    else
    {
        int res = dinic();
        cout << res << "\n";
        for (int i = 0; i < idx; i += 2)
        {
            int a = e[i ^ 1], b = e[i];
            if (a == S && b == 1)
                f[i] = INF;
            else if (a == 1 && b == n + 1)
                f[i] = INF;
            else if (a == n && b == n + n)
                f[i] = INF;
            else if (a == n + n && b == T)
                f[i] = INF;
        }
        cout << res + dinic() << "\n";
    }

    return 0;
}
