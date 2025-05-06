#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long range(const vector<long long> &pre, int l, int r)
{
    long long res = pre[r + 1] - pre[l];
    if (res < 0)
        res += MOD;
    return res;
}
int main()
{
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;
    vector<string> a(n);
    for (auto &s : a)
        cin >> s;
    vector<long long> f(m, 1), g(m, 0);
    for (int j = 1; j < m; ++j)
        if (a[0][j] == a[0][j - 1])
            g[j] = 1;
    for (int i = 1; i < n; ++i)
    {
        vector<long long> pf(m + 1, 0), pg(m + 1, 0);
        for (int j = 0; j < m; ++j)
        {
            pf[j + 1] = (pf[j] + f[j]) % MOD;
            pg[j + 1] = (pg[j] + g[j]) % MOD;
        }
        vector<long long> nf(m), ng(m);
        for (int j = 0; j < m; ++j)
        {
            int L = max(0, j - K);
            int R = min(m - 1, j + K);
            int L2 = max(0, j - K + 1);
            nf[j] = (range(pf, L, R) - range(pg, L2, R) + MOD) % MOD;
            if (j > 0 && a[i][j] == a[i][j - 1])
            {
                int Rg = min(m - 1, j + K - 1);
                int Lg = max(0, j - K);
                int Lg2 = max(0, j - K + 1);
                ng[j] = (range(pf, Lg, Rg) - range(pg, Lg2, Rg) + MOD) % MOD;
            }
            else
                ng[j] = 0;
        }
        f.swap(nf);
        g.swap(ng);
    }
    long long ans = 0;
    for (int j = 0; j < m; ++j)
    {
        ans += f[j] - g[j];
        if (ans >= MOD)
            ans -= MOD;
        if (ans < 0)
            ans += MOD;
    }
    cout << ans % MOD << '\n';
    return 0;
}
