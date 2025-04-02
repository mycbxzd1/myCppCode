#include <bits/stdc++.h>
using namespace std;
const int maxn = 210, maxm = (10210 + maxn) * 2, inf = 0x3f3f3f3f;
int head[maxn], ver[maxm], e[maxm], ne[maxm], L[maxm], idx = 1, tot = 0;
int n, m, S, T, delta[maxn];
int d[maxn], cur[maxn];
bool bfs()
{
    memset(d, -1, sizeof(d));
    queue<int> q;
    d[S] = 0, cur[S] = head[S];
    q.push(S);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = ne[i])
        {
            int y = ver[i];
            if (d[y] == -1 && e[i])
            {
                d[y] = d[x] + 1;
                cur[y] = head[y];
                if (y == T)
                    return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic(int u, int lim)
{
    if (u == T)
        return lim;
    int flow = 0;
    for (int i = cur[u]; i && lim > flow; i = ne[i])
    {
        cur[u] = i;
        int v = ver[i];
        if (d[v] == d[u] + 1 && e[i])
        {
            int t = dinic(v, min(e[i], lim - flow));
            if (!t)
                d[v] = -1;
            flow += t, e[i] -= t, e[i ^ 1] += t;
        }
    }
    return flow;
}

int main()
{
    auto add = [](int a, int b, int c, int d)
    {
        ver[++idx] = b, e[idx] = d - c, L[idx] = c, ne[idx] = head[a], head[a] = idx;
        ver[++idx] = a, e[idx] = 0, ne[idx] = head[b], head[b] = idx;
    };
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    S = 0, T = n + 1;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        delta[a] -= c, delta[b] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        if (delta[i] > 0)
            add(S, i, 0, delta[i]), tot += delta[i];
        else if (delta[i] < 0)
            add(i, T, 0, -delta[i]);
    }
    int res = 0, flow;
    while (bfs())
        while (flow = dinic(S, inf))
            res += flow;
    if (res != tot)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 2; i < 2 + m * 2; i += 2)
        cout << e[i ^ 1] + L[i] << endl;
}
