#include <bits/stdc++.h>
using namespace std;
const int INF = 9e8, N = 2005, M = 305;
int n, m, v, e, c[N], d[N], dis[M][M];
double k[N], f[N][N][2];
int main()
{
    cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= v; i++)
        for (int j = 1; j < i; j++)
            dis[j][i] = dis[i][j] = INF;
    for (int i = 1, a, b, w; i <= e; i++)
    {
        cin >> a >> b >> w;
        dis[a][b] = dis[b][a] = min(dis[a][b], w);
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j < i; j++)
                dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j][0] = f[i][j][1] = INF;
    f[1][0][0] = f[1][1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j][0] = min(f[i - 1][j][1] + k[i - 1] * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * dis[c[i - 1]][c[i]], f[i - 1][j][0] + dis[c[i - 1]][c[i]]);
            if (j)
                f[i][j][1] = min(f[i - 1][j - 1][1] + k[i - 1] * k[i] * dis[d[i - 1]][d[i]] + k[i - 1] * (1 - k[i]) * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * k[i] * dis[c[i - 1]][d[i]] + (1 - k[i - 1]) * (1 - k[i]) * dis[c[i - 1]][c[i]], f[i - 1][j - 1][0] + k[i] * dis[c[i - 1]][d[i]] + (1 - k[i]) * dis[c[i - 1]][c[i]]);
        }
    }
    double ans = INF;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= 1; j++)
            ans = min(ans, f[n][i][j]);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
