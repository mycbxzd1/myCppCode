#include <bits/stdc++.h>
using namespace std;

const int N = 107, INF = 2000000000;

struct Edge
{
    int from, to, cost, cap, next;
};

class MinCostFlow
{
public:
    int uid, source, sink, res, E, totalFlow, totalRow, totalCol;
    vector<int> rowNodes, colNodes, head, eIndex, dist, inQueue, level;
    vector<Edge> edges;

    MinCostFlow() : uid(0), res(0), E(1), totalFlow(0), totalRow(0), totalCol(0)
    {
        head.assign(N, 0);
        inQueue.assign(N, 0);
        dist.assign(N, 0);
        level.assign(N, 0);
        edges.resize(N * N);
    }

    void init(int n, int m)
    {
        rowNodes.resize(n + 1);
        colNodes.resize(m + 1);
        source = ++uid;
        sink = ++uid;
        for (int i = 1; i <= n; i++)
            rowNodes[i] = ++uid;
        for (int j = 1; j <= m; j++)
            colNodes[j] = ++uid;
    }

    void addEdge(int u, int v, int cost, int cap = 1)
    {
        edges[++E] = {u, v, cost, cap, head[u]};
        head[u] = E;
        edges[++E] = {v, u, -cost, 0, head[v]};
        head[v] = E;
    }

    bool bfs()
    {
        fill(dist.begin(), dist.end(), 0x3f3f3f3f);
        fill(level.begin(), level.end(), 0);
        queue<int> qu;
        dist[source] = 0;
        level[source] = 1;
        inQueue.assign(N, 0);
        inQueue[source] = 1;
        qu.push(source);
        while (!qu.empty())
        {
            int u = qu.front();
            qu.pop();
            inQueue[u] = 0;
            for (int i = head[u]; i; i = edges[i].next)
            {
                int v = edges[i].to, cost = edges[i].cost;
                if (edges[i].cap && dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                    level[v] = level[u] + 1;
                    if (!inQueue[v])
                    {
                        inQueue[v] = 1;
                        qu.push(v);
                    }
                }
            }
        }
        return level[sink] != 0;
    }

    int dfs(int u, int flow)
    {
        if (u == sink)
            return flow;
        int used = 0;
        for (int &i = eIndex[u]; i; i = edges[i].next)
        {
            int v = edges[i].to, cost = edges[i].cost;
            int available = min(edges[i].cap, flow - used);
            if (available && level[v] == level[u] + 1 && dist[u] + cost == dist[v])
            {
                int pushed = dfs(v, available);
                if (pushed)
                {
                    edges[i].cap -= pushed;
                    edges[i ^ 1].cap += pushed;
                    used += pushed;
                    if (used == flow)
                        return used;
                }
            }
        }
        return used;
    }
};

int main()
{
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    MinCostFlow mcf;
    mcf.init(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int cell;
            cin >> cell;
            mcf.res += cell;
            mcf.addEdge(mcf.rowNodes[i], mcf.colNodes[j], cell ? -1 : 1);
        }
    vector<int> rowDemand(n + 1), colDemand(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> rowDemand[i];
        mcf.totalRow += rowDemand[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> colDemand[j];
        mcf.totalCol += colDemand[j];
    }
    for (int i = 1; i <= n; i++)
        mcf.addEdge(mcf.source, mcf.rowNodes[i], 0, rowDemand[i]);
    for (int j = 1; j <= m; j++)
        mcf.addEdge(mcf.colNodes[j], mcf.sink, 0, colDemand[j]);
    while (mcf.bfs())
    {
        mcf.eIndex = mcf.head;
        while (int pushed = mcf.dfs(mcf.source, INF))
        {
            mcf.res += pushed * mcf.dist[mcf.sink];
            mcf.totalFlow += pushed;
        }
    }
    cout << ((mcf.totalRow == mcf.totalFlow && mcf.totalFlow == mcf.totalCol) ? mcf.res : -1) << "\n";
    return 0;
}
