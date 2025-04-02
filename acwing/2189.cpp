#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = 21000;
const int INF = 1e8;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N], A[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, t;
    cin >> n >> m >> s >> t;
    S = 0, T = n + 1;
    memset(h, -1, sizeof h);
    memset(A, 0, sizeof A);
    idx = 0;
    
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, d - c);
        A[a] -= c;
        A[b] += c;
    }
    
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            add(S, i, A[i]);
            tot += A[i];
        } else if (A[i] < 0) {
            add(i, T, -A[i]);
        }
    }
    add(t, s, INF);
    
    function<bool()> bfs = [&]() -> bool {
        memset(d, -1, sizeof d);
        int hh = 0, tt = 0;
        q[0] = S;
        d[S] = 0;
        memcpy(cur, h, sizeof h);
        while (hh <= tt) {
            int u = q[hh++];
            for (int i = h[u]; i != -1; i = ne[i]) {
                int ver = e[i];
                if (d[ver] == -1 && f[i]) {
                    d[ver] = d[u] + 1;
                    q[++tt] = ver;
                }
            }
        }
        return d[T] != -1;
    };

    function<int(int, int)> find = [&](int u, int limit) -> int {
        if (u == T) return limit;
        int flow = 0; 
        for (int &i = cur[u]; i != -1 && flow < limit; i = ne[i]) {
            int ver = e[i];
            if (d[ver] == d[u] + 1 && f[i]) {
                int t = find(ver, min(f[i], limit - flow));
                if (!t)
                    d[ver] = -1;
                else {
                    f[i] -= t;
                    f[i ^ 1] += t;
                    flow += t;
                }
            }
        }
        return flow;
    };

    function<int()> dinic = [&]() -> int {
        int ret = 0, flow;
        while (bfs())
            while ((flow = find(S, INF)) > 0)
                ret += flow;
        return ret;
    };

    if (dinic() < tot)
        cout << "No Solution" << "\n";
    else {
        int res = f[idx - 1];
        f[idx - 1] = f[idx - 2] = 0;
        S = s, T = t;
        cout << res + dinic();
    }
    return 0;
}
