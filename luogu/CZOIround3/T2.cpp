#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int qpow(int a, int e)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
int32_t main()
{
    auto mod_inv = [&](int x) -> int
    { return qpow(x, mod - 2); } ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<tuple<int, int, int>> qs(T);
    int maxn = 0;
    for (int i = 0; i < T; i++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        qs[i] = make_tuple(n, m, k);
        maxn = max(maxn, n);
    }
    vector<int> inv(maxn + 1, 0);
    if (maxn >= 1)
    {
        inv[1] = 1;
        for (int i = 2; i <= maxn; i++)
            inv[i] = mod_inv(i);
    }
    for (auto &q : qs)
    {
        int n, m, k;
        tie(n, m, k) = q;
        if (k == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        if (m == 0)
        {
            cout << qpow(k, n) << "\n";
            continue;
        }
        int p = qpow(k, n);
        int invk = mod_inv(k);
        int E = 1;
        int ans = p;
        for (int j = 1; j < n; j++)
        {
            E = E * ((int)m + j - 1) % mod * inv[j] % mod;
            p = p * invk % mod;
            ans = (ans + E * p) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
