#include <bits/stdc++.h>
using namespace std;
const int N = 1006, C = 106, INF = 0x3f3f3f3f;
int n, m, p[N], d[N][C];
vector<tuple<int, int>> e[N];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int c, st, ed;
        cin >> c >> st >> ed;
        priority_queue<tuple<int, int, int>> pq;
        memset(d, INF, sizeof(d));
        pq.emplace(0, st, 0);
        d[st][0] = 0;

        while (!pq.empty())
        {
            auto [cost, city, fuel] = pq.top();
            pq.pop();
            cost = -cost;
            if (city == ed)
            {
                cout << cost << '\n';
                break;
            }
            if (d[city][fuel] < cost)
                continue;
            if (fuel < c && d[city][fuel + 1] > cost + p[city])
            {
                d[city][fuel + 1] = cost + p[city];
                pq.emplace(-d[city][fuel + 1], city, fuel + 1);
            }
            for (auto [y, z] : e[city])
                if (z <= fuel && d[y][fuel - z] > cost)
                {
                    d[y][fuel - z] = cost;
                    pq.emplace(-cost, y, fuel - z);
                }
        }
        if (d[ed][0] == INF)
            cout << "impossible\n";
    }
}
