#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 80010, INF = 100000000;
int n, m, K, S, T, h[N], e[M], f[M], w[M], ne[M], idx, q[N], d[N], cur[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto add = [&](int a, int b, int c) -> void
    {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
        e[idx] = a, w[idx] = c, ne[idx] = h[b], h[b] = idx++;
    };

    auto bfs = [&]() -> bool
    {
        int hh = 0, tt = 0;
        memset(d, -1, sizeof(d));
        q[0] = S;
        d[S] = 0;
        cur[S] = h[S];
        while (hh <= tt)
        {
            int t = q[hh++];
            for (int i = h[t]; i != -1; i = ne[i])
            {
                int ver = e[i];
                if (d[ver] == -1 && f[i] > 0)
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
    };

    function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == T)
            return limit;
        int flow = 0;
        for (int i = cur[u]; i != -1 && flow < limit; i = ne[i])
        {
            cur[u] = i;
            int ver = e[i];
            if (d[ver] == d[u] + 1 && f[i] > 0)
            {
                int t = dfs(ver, min(f[i], limit - flow));
                if (!t)
                    d[ver] = -1;
                else
                {
                    f[i] -= t;
                    f[i ^ 1] += t;
                    flow += t;
                }
            }
        }
        return flow;
    };

    auto dinic = [&]() -> int
    {
        int r = 0, flow;
        while (bfs())
        {
            for (int i = 1; i <= n; i++)
                cur[i] = h[i];
            while ((flow = dfs(S, INF)) != 0)
                r += flow;
        }
        return r;
    };

    auto check = [&](int mid) -> bool
    {
        for (int i = 0; i < idx; i++)
            f[i] = (w[i] <= mid) ? 1 : 0;
        return dinic() >= K;
    };

    cin >> n >> m >> K;
    S = 1, T = n;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int l = 1, r = 1000000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << "\n";
    return 0;
}
