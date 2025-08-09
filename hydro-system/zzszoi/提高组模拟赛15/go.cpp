#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Sec
{
    int d[2][2];
    Sec(int v = INF) { d[0][0] = d[0][1] = d[1][0] = d[1][1] = v; }
};
int main()
{
    freopen("go.in", "r", stdin);
    freopen("go.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string s[2];
    cin >> s[0] >> s[1];
    int LOG = 32 - __builtin_clz(N);
    vector<vector<Sec>> f(LOG, vector<Sec>(N + 2));
    vector<int> canVert(N + 2, 0);
    for (int i = 1; i <= N; ++i)
        canVert[i] = (s[0][i - 1] == 'P' && s[1][i - 1] == 'P');
    for (int i = 1; i < N; ++i)
    {
        bool ok[4] = {s[0][i - 1] == 'P', s[1][i - 1] == 'P', s[0][i] == 'P', s[1][i] == 'P'};
        vector<int> g[4];
        auto add = [&](int u, int v)
        { g[u].push_back(v); g[v].push_back(u); };
        if (ok[0] && ok[2])
            add(0, 2);
        if (ok[1] && ok[3])
            add(1, 3);
        if (ok[0] && ok[1])
            add(0, 1);
        if (ok[2] && ok[3])
            add(2, 3);
        for (int stRow = 0; stRow < 2; ++stRow)
        {
            int st = stRow;
            if (!ok[st])
            {
                f[0][i].d[stRow][0] = f[0][i].d[stRow][1] = INF;
                continue;
            }
            int dist[4];
            fill(dist, dist + 4, INF);
            queue<int> q;
            q.push(st);
            dist[st] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : g[u])
                    if (dist[v] == INF)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
            }
            for (int edRow = 0; edRow < 2; ++edRow)
            {
                int node = 2 + edRow;
                f[0][i].d[stRow][edRow] = dist[node];
            }
        }
    }
    for (int k = 1; k < LOG; ++k)
    {
        int len = 1 << k, half = len >> 1;
        for (int i = 1; i + len <= N; ++i)
        {
            int mid = i + half;
            Sec &L = f[k - 1][i];
            Sec &R = f[k - 1][mid];
            Sec &res = f[k][i];
            for (int a = 0; a < 2; ++a)
                for (int b = 0; b < 2; ++b)
                {
                    int best = INF;
                    for (int c = 0; c < 2; ++c)
                        for (int d = 0; d < 2; ++d)
                        {
                            if (L.d[a][c] == INF || R.d[d][b] == INF)
                                continue;
                            int cross = (c == d) ? 0 : (canVert[mid] ? 1 : INF);
                            if (cross == INF)
                                continue;
                            best = min(best, L.d[a][c] + cross + R.d[d][b]);
                        }
                    res.d[a][b] = best;
                }
        }
    }
    auto id2rc = [&](int id) -> pair<int, int>
    {
        if (id <= N)
            return {0, id};
        else
            return {1, id - N};
    };
    auto sameColAns = [&](int col, int r1, int r2) -> int
    {
        if (r1 == r2)
            return 0;
        return canVert[col] ? 1 : -1;
    };
    function<int(int, int)> query = [&](int L, int R) -> int
    {
        auto [rL, cL] = id2rc(L);
        auto [rR, cR] = id2rc(R);
        if (s[rL][cL - 1] == 'X' || s[rR][cR - 1] == 'X')
            return -1;
        if (cL == cR)
            return sameColAns(cL, rL, rR);
        if (cL > cR)
            return query(R, L);
        int cur[2] = {INF, INF};
        cur[rL] = 0;
        int pos = cL;
        for (int k = LOG - 1; k >= 0; --k)
        {
            int len = 1 << k;
            if (pos + len <= cR)
            {
                int nxt[2] = {INF, INF};
                for (int a = 0; a < 2; ++a)
                    if (cur[a] < INF)
                    {
                        for (int b = 0; b < 2; ++b)
                        {
                            int w = f[k][pos].d[a][b];
                            if (w < INF)
                                nxt[b] = min(nxt[b], cur[a] + w);
                        }
                    }
                cur[0] = nxt[0];
                cur[1] = nxt[1];
                pos += len;
            }
        }
        int ans = cur[rR];
        return (ans >= INF) ? -1 : ans;
    };
    while (M--)
    {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }
    return 0;
}
