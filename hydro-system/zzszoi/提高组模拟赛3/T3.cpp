#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX / 2;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, long long>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> faithCities(k);
    for (int i = 0; i < k; i++)
        cin >> faithCities[i];
    vector<vector<pair<int, long long>>> graph(n + 1);
    for (auto &e : edges)
    {
        int u, v;
        long long w;
        tie(u, v, w) = e;
        graph[u].push_back({v, w});
    }
    bool negativeEdge = false;
    for (auto &e : edges)
    {
        int u, v;
        long long w;
        tie(u, v, w) = e;
        if (w < 0)
        {
            negativeEdge = true;
            break;
        }
    }
    auto dijkstra = [&](int src) -> vector<long long>
    {
        vector<long long> dist(n + 1, INF);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [curD, u] = pq.top();
            pq.pop();
            if (curD > dist[u])
                continue;
            for (auto &edge : graph[u])
            {
                int v = edge.first;
                long long w = edge.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    auto bellman_ford = [&](int src) -> vector<long long>
    {
        vector<long long> dist(n + 1, INF);
        dist[src] = 0;
        for (int i = 1; i < n; i++)
        {
            bool updated = false;
            for (auto &e : edges)
            {
                int u, v;
                long long w;
                tie(u, v, w) = e;
                if (dist[u] < INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated)
                break;
        }
        return dist;
    };

    long long ans = INF;
    for (int i = 0; i < k; i++)
    {
        int src = faithCities[i];
        vector<long long> dist;
        if (!negativeEdge)
            dist = dijkstra(src);
        else
            dist = bellman_ford(src);
        vector<bool> affected(n + 1, false);
        if (negativeEdge)
        {
            for (auto &e : edges)
            {
                int u, v;
                long long w;
                tie(u, v, w) = e;
                if (dist[u] < INF && dist[u] + w < dist[v])
                    affected[v] = true;
            }
            queue<int> q;
            for (int i = 1; i <= n; i++)
                if (affected[i])
                    q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto &edge : graph[u])
                {
                    int v = edge.first;
                    if (!affected[v])
                    {
                        affected[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        for (int j = 0; j < k; j++)
        {
            if (i == j)
                continue;
            int dst = faithCities[j];
            if (negativeEdge && affected[dst])
                continue;
            ans = min(ans, dist[dst]);
        }
        if (ans == 0)
            break;
    }
    cout << (ans >= INF ? -1 : ans) << "\n";
    return 0;
}
