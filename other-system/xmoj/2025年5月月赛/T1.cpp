#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
int qpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    freopen("oncemore.in", "r", stdin);
    freopen("oncemore.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[N] = qpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % MOD;
    int ans = 0;
    for (int k = 1; k <= N; ++k)
    {
        int comb = fact[N] * invfact[k] % MOD * invfact[N - k] % MOD;
        int ways = qpow(k, N - k);
        ans = (ans + comb * ways) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
