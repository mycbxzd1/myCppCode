#include <bits/stdc++.h>
using namespace std;
#define int long long
static const int MOD = 1000000007;
int qpow(int a, int b, int M)
{
    int res = 1 % M;
    a = a % M;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}
int inv(int n, int M)
{
    return qpow(n, M - 2, M);
}

signed main()
{
    freopen("cp.in", "r", stdin);
    freopen("cp.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int invN = inv(n, MOD);
        int ans = ((n - 1) % MOD + invN) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
