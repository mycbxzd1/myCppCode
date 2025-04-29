#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
long long ans = 0;
const int INF = 0x3f3f3f3f;
int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    cin >> n >> m;
    vector<int> s(n + 1), t(n + 1);
    vector<vector<int>> p(405, vector<int>(405, INF));
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        p[a][b] = min(p[a][b], c);
    }
    for (int k = 1; k <= 400; k++)
    {
        p[k][k] = 0;
        for (int i = 1; i <= 400; i++)
            for (int j = 1; j <= 400; j++)
                if (p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = (p[i][k] + p[k][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        int res = INF;
        for (int j = 1; j <= 400; j++)
            res = min(res, p[s[i]][j] + p[t[i]][j]);
        if (res == INF)
        {
            cout << -1;
            goto end;
        }
        ans += res;
    }
    cout << ans;
end:
    return 0;
}