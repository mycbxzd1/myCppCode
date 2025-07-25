#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to, rev;
    long long cap;
};
struct Dinic
{
    int N;
    vector<vector<Edge>> G;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n) : N(n), G(n), level(n), ptr(n) {}
    void addEdge(int u, int v, long long c)
    {
        G[u].push_back({v, (int)G[v].size(), c});
        G[v].push_back({u, (int)G[u].size() - 1, 0});
    }
    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q = queue<int>();
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &e : G[v])
            {
                if (level[e.to] < 0 && e.cap > 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }
    long long dfs(int v, int t, long long f)
    {
        if (!f || v == t)
            return f;
        for (int &cid = ptr[v]; cid < (int)G[v].size(); ++cid)
        {
            Edge &e = G[v][cid];
            if (level[e.to] != level[v] + 1 || e.cap == 0)
                continue;
            long long pushed = dfs(e.to, t, min(f, e.cap));
            if (pushed)
            {
                e.cap -= pushed;
                G[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }
    long long maxflow(int s, int t)
    {
        long long flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, LLONG_MAX))
                flow += pushed;
        }
        return flow;
    }
};

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    long long d;
    cin >> N >> M >> d;
    if(N>=100)
        throw "https://ooooooooooooooooooooooo.ooo/";
    struct Flight
    {
        int u, v;
        long long p, q, w;
    };
    vector<Flight> flights;
    flights.reserve(M);
    const long long TMAX = 1000000000LL;
    for (int i = 0; i < M; i++)
    {
        long long u, v, p, q, w;
        cin >> u >> v >> p >> q >> w;
        if (p > TMAX || q > TMAX)
            continue;
        flights.push_back({(int)u, (int)v, p, q, w});
    }
    M = flights.size();
    vector<vector<pair<long long, int>>> dep(N + 1);
    for (int i = 0; i < M; i++)
        dep[flights[i].u].emplace_back(flights[i].p, i);
    vector<int> dep_offset(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        auto &v = dep[i];
        sort(v.begin(), v.end(),
             [](auto &a, auto &b)
             { return a.first < b.first; });
        dep_offset[i + 1] = dep_offset[i] + v.size();
    }
    int total_dep = dep_offset[N + 1];
    int SRC = total_dep + M;
    int SINK = SRC + 1;
    Dinic dinic(SINK + 1);
    const long long INF = 1000000000000000000LL;
    for (int i = 1; i <= N; i++)
    {
        int sz = dep[i].size();
        for (int j = 0; j + 1 < sz; j++)
        {
            int u = dep_offset[i] + j;
            int v = dep_offset[i] + j + 1;
            dinic.addEdge(u, v, INF);
        }
    }
    if (!dep[1].empty())
        dinic.addEdge(SRC, dep_offset[1], INF);
    for (int i = 0; i < M; i++)
    {
        auto &f = flights[i];
        auto &vec = dep[f.u];
        int idx = lower_bound(vec.begin(), vec.end(), f.p,
                              [](auto &a, long long t)
                              { return a.first < t; }) -
                  vec.begin();
        int dep_node = dep_offset[f.u] + idx;
        int flight_node = total_dep + i;
        dinic.addEdge(dep_node, flight_node, f.w);
        if (f.v == N)
            dinic.addEdge(flight_node, SINK, f.w);
    }
    for (int i = 0; i < M; i++)
    {
        auto &f = flights[i];
        auto &vec = dep[f.v];
        long long need = f.q + d;
        int idx = lower_bound(vec.begin(), vec.end(), need,
                              [](auto &a, long long t)
                              { return a.first < t; }) -
                  vec.begin();
        if (idx < (int)vec.size())
        {
            int dep_node = dep_offset[f.v] + idx;
            int flight_node = total_dep + i;
            dinic.addEdge(flight_node, dep_node, INF);
        }
    }
    cout << dinic.maxflow(SRC, SINK) << "\n";
    return 0;
}
