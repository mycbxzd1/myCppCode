#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph[u].push_back(v);
        }
        int Bsize = (n + 63) / 64;
        vector<vector<unsigned long long>> reachable(n, vector<unsigned long long>(Bsize, 0ULL));
        for (int i = n - 1; i >= 0; i--)
        {
            reachable[i][i / 64] |= (1ULL << (i % 64));
            for (int v : graph[i])
                for (int b = 0; b < Bsize; b++)
                    reachable[i][b] |= reachable[v][b];
        }
        vector<int> A(n), Bval(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> Bval[i];
        for (int i = 0; i < q; i++)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                swap(A[x], A[y]);
            }
            else if (op == 2)
            {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                swap(Bval[x], Bval[y]);
            }
            else if (op == 3)
            {
                int x, l, r;
                cin >> x >> l >> r;
                x--;
                int ans = 0;
                for (int blk = 0; blk < Bsize; blk++)
                {
                    unsigned long long bits = reachable[x][blk];
                    while (bits)
                    {
                        int pos = __builtin_ctzll(bits);
                        int node = blk * 64 + pos;
                        if (node >= n)
                            break;
                        if (A[node] >= l && A[node] <= r)
                            ans = max(ans, Bval[node]);

                        bits &= bits - 1;
                    }
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}