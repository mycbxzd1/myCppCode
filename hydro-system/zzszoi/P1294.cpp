#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, f[21][21][2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    f[1][1][0] = f[1][1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int p = j; p <= i - 1; p++)
                f[i][j][0] += f[i - 1][p][1];
            for (int p = 1; p <= j - 1; p++)
                f[i][j][1] += f[i - 1][p][0];
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        bool used[21]{};
        int last, k;
        for (int j = 1; j <= n; j++)
        {
            if (f[n][j][1] >= m)
            {
                last = j, k = 1;
                break;
            }
            m -= f[n][j][1];
            if (f[n][j][0] >= m)
            {
                last = j, k = 0;
                break;
            }
            m -= f[n][j][0];
        }
        used[last] = 1;
        cout << last;
        for (int i = 2; i <= n; i++)
        {
            k ^= 1;
            int j = 0;
            for (int len = 1; len <= n; len++)
            {
                if (used[len])
                    continue;
                j++;
                if ((k == 0 && len < last) || (k == 1 && len > last))
                {
                    if (f[n - i + 1][j][k] >= m)
                    {
                        last = len;
                        break;
                    }
                    m -= f[n - i + 1][j][k];
                }
            }
            used[last] = 1;
            cout << ' ' << last;
        }
        cout << '\n';
    }
}
