#include <bits/stdc++.h>
using namespace std;
const int N = 15;
double a[N][N], b[N], c[N][N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]),
            b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (fabs(c[j][i]) > 1e-8)
            {
                for (int k = 1; k <= n; k++)
                    swap(c[i][k], c[j][k]);
                swap(b[i], b[j]);
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            double rate = c[j][i] / c[i][i];
            for (int k = i; k <= n; k++)
                c[j][k] -= c[i][k] * rate;
            b[j] -= b[i] * rate;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(3) << b[i] / c[i][i] << " ";
}