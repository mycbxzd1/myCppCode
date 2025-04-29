#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXM = 2005;

int N, M;
int U[MAXN];
vector<pair<int, int>> adj[MAXN];
int dp[MAXN][MAXM];
int maxTime[MAXN];

void dfs(int u, int parent)
{
    dp[u][0] = U[u];
    for (int t = 1; t <= M; ++t)
        dp[u][t] = -1;
    maxTime[u] = 0;
    for (auto &e : adj[u])
    {
        int v = e.first, w = e.second;
        if (v == parent)
            continue;
        dfs(v, u);
        static int tmp[MAXM];
        for (int t = 0; t <= M; ++t)
            tmp[t] = dp[u][t];

        int tcost = 2 * w;
        int limit_u = min(maxTime[u], M - tcost);
        for (int t_u = 0; t_u <= limit_u; ++t_u)
        {
            if (dp[u][t_u] < 0)
                continue;
            int rem = M - tcost - t_u;
            int limit_v = min(maxTime[v], rem);
            for (int t_v = 0; t_v <= limit_v; ++t_v)
            {
                if (dp[v][t_v] < 0)
                    continue;
                int t_new = t_u + tcost + t_v;
                int val = dp[u][t_u] + dp[v][t_v];
                if (val > tmp[t_new])
                    tmp[t_new] = val;
            }
        }
        for (int t = 0; t <= M; ++t)
            dp[u][t] = tmp[t];
        int newMax = 0;
        for (int t = M; t >= 0; --t)
            if (dp[u][t] >= 0)
            {
                newMax = t;
                break;
            }
        maxTime[u] = newMax;
    }
}

int main()
{
    freopen("tulip.in", "r", stdin);
    freopen("tulip.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> U[i];
        adj[i].clear();
    }
    for (int i = 0; i < N - 1; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
    }
    dfs(0, -1);
    int ans = 0;
    for (int t = 0; t <= M; ++t)
        ans = max(ans, dp[0][t]);
    cout << ans << "\n";
    return 0;
}