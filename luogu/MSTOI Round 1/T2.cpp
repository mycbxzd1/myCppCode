#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= mod;
    }
    vector<char> type(q);
    vector<int> l(q), r(q), k(q);
    int maxK = 2;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        type[i] = t;
        if (t == 2)
        {
            cin >> l[i] >> r[i] >> k[i];
            maxK = max(maxK, k[i]);
        }
        else
            cin >> l[i] >> r[i];
    }
    vector<vector<int>> sum(maxK + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int x = a[i], pw = x;
        sum[1][i] = sum[1][i - 1] + x;
        if (sum[1][i] >= mod)
            sum[1][i] -= mod;
        for (int j = 2; j <= maxK; j++)
        {
            pw = pw * x % mod;
            sum[j][i] = sum[j][i - 1] + pw;
            if (sum[j][i] >= mod)
                sum[j][i] -= mod;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int L = l[i], R = r[i];
        if (type[i] == 1)
        {
            int ans = sum[1][R] - sum[1][L - 1];
            if (ans < 0)
                ans += mod;
            cout << ans << "\n";
        }
        else if (type[i] == 2)
        {
            int ans = sum[k[i]][R] - sum[k[i]][L - 1];
            if (ans < 0)
                ans += mod;
            cout << ans << "\n";
        }
        else
        {
            int len = R - L + 1;
            int s1 = (sum[1][R] - sum[1][L - 1] + mod) % mod;
            int s2 = (sum[2][R] - sum[2][L - 1] + mod) % mod;
            int res = (1LL * len * s2 % mod - s1 * s1 % mod + mod) % mod;
            cout << res << "\n";
        }
    }
    return 0;
}
