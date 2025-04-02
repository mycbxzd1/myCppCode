#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans[5][1005], a, b, m = 1, q, t, x;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> q >> n;
    q--;
    for (int t = 0; t <= 9; t++)
    {
        x = t, m = 1;
        while (m <= q)
        {
            int a = q / (m * 10), b = q / m % 10, c = q % m;
            if (x)
                (b > x ? ans[2][t] += (a + 1) * m : (b == x ? ans[2][t] += a * m + c + 1 : ans[2][t] += a * m));
            else
                (b ? ans[2][t] += a * m : ans[2][t] += (a - 1) * m + c + 1);
            m *= 10;
        }
    }
    for (int t = 0; t <= 9; t++)
    {
        x = t, m = 1;
        while (m <= n)
        {
            int a = n / (m * 10), b = n / m % 10, c = n % m;
            if (x)
                (b > x ? ans[1][t] += (a + 1) * m : (b == x ? ans[1][t] += a * m + c + 1 : ans[1][t] += a * m));
            else
                (b ? ans[1][t] += a * m : ans[1][t] += (a - 1) * m + c + 1);
            m *= 10;
        }
    }
    for (int i = 0; i <= 9; i++)
        cout << ans[1][i] - ans[2][i] << " ";
    return 0;
}
