#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, d[N], vis[N];
vector<int> g[N];

bool run(int s)
{
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, function<bool(tuple<int, int>, tuple<int, int>)>> q(
        [](const auto &a, const auto &b)
        {
            return get<0>(a) > get<0>(b);
        });

    q.push({d[s], s});
    int cnt = 0;

    while (!q.empty())
    {
        auto [_, u] = q.top();
        q.pop();
        if (vis[u] == s)
            continue;
        vis[u] = s;
        if (d[u] > cnt)
            return false;
        cnt++;
        for (int v : g[u])
            if (vis[v] < s)
                q.push({d[v], v});
    }

    return cnt == n;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i];
            vis[i] = 0;
            g[i].clear();
        }
        for (int i = 1, u, v; i <= m; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0 && vis[i] == 0 && run(i))
            {
                cout << "YES\n";
                ok = true;
                break;
            }
        }
        if (!ok)
            cout << "NO\n";
    }
    return 0;
}
