#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long kpow(long long a, long long n = mod - 2)
{
    long long r = 1;
    while (n)
    {
        if (n & 1)
            r = r * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return r;
}
int main()
{
    freopen("study.in", "r", stdin);
    freopen("study.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> g(N);
    for (auto &s : g)
        cin >> s;
    const long long INV2 = kpow(2);
    const int R = N + 1;
    vector<long long> dp(R + 2), ndp(R + 2);
    for (int r = 1; r <= R; ++r)
    {
        if (r == 1)
            dp[r] = 1;
        else
            dp[r] = (g[r - 2][0] == '.') ? INV2 : 0;
    }
    auto A = [&](int row, int col) -> long long
    {
        if (row > N)
            return 1;
        return (g[row - 1][col - 1] == '.') ? INV2 : 0;
    };
    auto B = [&](int row, int col) -> long long
    {
        if (row == 1)
            return 1;
        return (g[row - 2][col - 1] == '.') ? INV2 : 0;
    };
    for (int j = 1; j < N; ++j)
    {
        fill(ndp.begin(), ndp.end(), 0);
        long long prefix = 0;
        for (int r = 1; r <= R; ++r)
        {
            ndp[r] = (ndp[r] + dp[r]) % mod;
            long long add = prefix * B(r, j + 1) % mod;
            ndp[r] = (ndp[r] + add) % mod;
            prefix = (prefix + dp[r] * A(r, j)) % mod;
        }
        dp.swap(ndp);
    }
    long long paths = 0;
    for (int r = 1; r <= R; ++r)
    {
        long long endFac = A(r, N);
        paths = (paths + dp[r] * endFac) % mod;
    }
    long long dotCnt = 0;
    for (auto &s : g)
        for (char c : s)
            if (c == '.')
                ++dotCnt;
    long long ans = paths * kpow(2, dotCnt) % mod;
    cout << ans << '\n';
    return 0;
}
