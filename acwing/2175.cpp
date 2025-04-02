#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10, maxm = 6000 + 10;
const int inf = 0x3f3f3f3f;
int head[maxn], ver[maxm], e[maxm], ne[maxm], tot = 1;
int n, m, S, T;

int d[maxn], cur[maxn];
bool bfs()
{
    memset(d, -1, sizeof d);
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
            if (d[y] == -1 && e[i] > 0)
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

int dinic()
{
    int flow = 0;
    while (bfs())
    {
        for (int i = 0; i < n; i++)
            cur[i] = head[i];

        int u = S;
        vector<int> st, ed;
        while (true)
        {
            if (u == T)
            {
                int bottleneck = inf;
                for (int edge : ed)
                    bottleneck = min(bottleneck, e[edge]);
                flow += bottleneck;
                while (!ed.empty())
                {
                    int edge = ed.back();
                    ed.pop_back();
                    e[edge] -= bottleneck;
                    e[edge ^ 1] += bottleneck;
                    if (e[edge] == 0)
                    {
                        u = st.back();
                        st.pop_back();
                        break;
                    }
                }
                if (ed.empty())
                    u = S;
            }
            else
            {
                bool advanced = false;
                for (int i = cur[u]; i; i = ne[i])
                {
                    int v = ver[i];
                    if (e[i] > 0 && d[v] == d[u] + 1)
                    {
                        advanced = true;
                        cur[u] = i;
                        st.push_back(u);
                        ed.push_back(i);
                        u = v;
                        break;
                    }
                }
                if (!advanced)
                {
                    if (st.empty())
                        break;
                    u = st.back();
                    st.pop_back();
                    ed.pop_back();
                }
            }
        }
    }
    return flow;
}
int main()
{
    auto add = [&](int a, int b, int c)
    {
        ver[++tot] = b;
        e[tot] = c;
        ne[tot] = head[a];
        head[a] = tot;
        ver[++tot] = a;
        e[tot] = 0;
        ne[tot] = head[b];
        head[b] = tot;
    };
    cin >> m >> n;
    S = 0, T = n + 1;
    for (int i = 1; i <= m; i++)
        add(S, i, 1);
    for (int i = m + 1; i <= n; i++)
        add(i, T, 1);
    int a, b;
    while (cin >> a >> b && a != -1)
        add(a, b, 1);
    cout << dinic() << endl;
    for (int i = 2; i <= tot; i += 2)
        if (ver[i] > m && ver[i] <= n && e[i] == 0)
            cout << ver[i ^ 1] << " " << ver[i];
}
