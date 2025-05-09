#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Op
{
    int x1, x2, y1, y2, v;
};
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<Op> ops(n);
    vector<array<int, 4>> qs(m);
    int maxX = 0, maxY = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ops[i].x1 >> ops[i].x2 >> ops[i].y1 >> ops[i].y2 >> ops[i].v;
        maxX = max(maxX, ops[i].x2);
        maxY = max(maxY, ops[i].y2);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> qs[i][0] >> qs[i][1] >> qs[i][2] >> qs[i][3];
        maxX = max(maxX, qs[i][1]);
        maxY = max(maxY, qs[i][3]);
    }
    vector<vector<int>> V(maxX + 2, vector<int>(maxY + 2, 0));
    for (auto &op : ops)
        for (int x = op.x1; x <= op.x2; ++x)
            for (int y = op.y1; y <= op.y2; ++y)
                V[x][y] = max(V[x][y], (int)op.v);
    vector<vector<int>> S(maxX + 2, vector<int>(maxY + 2, 0));
    for (int i = 1; i <= maxX; i++)
        for (int j = 1; j <= maxY; j++)
            S[i][j] = V[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    for (auto &q : qs)
    {
        int x1 = q[0], x2 = q[1], y1 = q[2], y2 = q[3];
        int ans = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}
