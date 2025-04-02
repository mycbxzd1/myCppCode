#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 20010;
const int INF = 1e9;
int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], pre[N];
bool st[N];
bool bfs()
{
    memset(st, false, sizeof(st));
    int hh = 0, tt = 0;
    q[0] = S, d[S] = INF, st[S] = true;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!st[j] && f[i])
            {
                st[j] = true;
                d[j] = min(d[t], f[i]);
                pre[j] = i;
                if (j == T)
                    return true;
                q[++tt] = j;
            }
        }
    }
    return false;
}
int main()
{
    auto add = [&](int a, int b, int c)
    {
        e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
        e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
    };
    int a, b, c;
    memset(h, -1, sizeof h);
    cin >> n >> m >> S >> T;
    while (m--)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int flow = 0;
    while (bfs())
    {
        flow += d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
            f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
    }
    cout << flow;
    return 0;
}