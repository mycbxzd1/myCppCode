#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;
long long qpow(long long a, long long e = MOD - 2)
{
    long long r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main()
{
    freopen("calculate.in", "r", stdin);
    freopen("calculate.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    if (M % K != 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    int T = M / K;
    int MAXF = N + T + 5;
    vector<long long> fact(MAXF, 1), invf(MAXF, 1);
    for (int i = 1; i < MAXF; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invf[MAXF - 1] = qpow(fact[MAXF - 1]);
    for (int i = MAXF - 2; i >= 0; i--)
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    auto C = [&](int n, int r) -> long long
    {
        if (r == 0)
            return 1;
        if (n < r || r < 0)
            return 0;
        return fact[n] * invf[r] % MOD * invf[n - r] % MOD;
    };
    long long ans = 0;
    int L = N - K + 1;
    for (int t = 0; t <= T; t++)
    {
        long long ways_sub = C(L + t - 1, t);
        long long ways_pt = C(N + (T - t) - 1, T - t);
        ans = (ans + ways_sub * ways_pt) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
