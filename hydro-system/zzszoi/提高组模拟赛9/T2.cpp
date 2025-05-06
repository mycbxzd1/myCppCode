#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int addmod(int a, int b)
{
    int s = a + b;
    if (s >= MOD)
        s -= MOD;
    return s;
}
int submod(int a, int b)
{
    int s = a - b;
    if (s < 0)
        s += MOD;
    return s;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    string str;
    int d;
    cin >> str >> d;
    int e = 1;
    while (d % 2 == 0)
        d /= 2, e *= 2;
    while (d % 5 == 0)
        d /= 5, e *= 5;
    int n = str.size();
    int m = d * e;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = (pre[i] * 10 + (str[i] - '0')) % m;
    auto inv_mod = [](int a, int mod)
    {
        a %= mod;
        if (a < 0)
            a += mod;
        int b = mod, u = 0, v = 1;
        while (a)
        {
            int t = b / a;
            b -= a * t;
            swap(a, b);
            u -= v * t;
            swap(u, v);
        }
        if (u < 0)
            u += mod;
        return u;
    };
    int inv10 = (d == 1 ? 0 : inv_mod(10, d));
    vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 0; i < n; ++i)
        pw[i + 1] = (pw[i] * inv10) % d;
    vector<int> ba(20);
    ba[0] = 1;
    for (int i = 1; i < 20; ++i)
        ba[i] = (ba[i - 1] * 10) % m;
    vector<int> f(n + 1), g(n + 1), of(d), og(d);
    g[0] = 1;
    int sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        int h = (d == 1 ? 0 : (pre[i] * pw[i]) % d);
        f[i] = addmod(f[i], sum);
        if (pre[i] % e == 0)
            f[i] = addmod(f[i], of[h]), g[i] = addmod(g[i], og[h]);
        sum = addmod(sum, g[i]);
        of[h] = submod(of[h], g[i]);
        int t = addmod(f[i], g[i]);
        og[h] = addmod(og[h], t);
        for (int j = i + 1; j <= n && j < i + 20; ++j)
        {
            int diff = (pre[j] - pre[i] * ba[j - i]) % m;
            if (diff < 0)
                diff += m;
            if (diff == 0)
            {
                f[j] = submod(f[j], g[i]);
                int t2 = addmod(f[i], g[i]);
                g[j] = addmod(g[j], t2);
            }
            if (pre[j] % e == 0 && h == (pre[j] * pw[j]) % d)
            {
                f[j] = addmod(f[j], g[i]);
                int t2 = addmod(f[i], g[i]);
                g[j] = submod(g[j], t2);
            }
        }
    }
    cout << addmod(f[n], g[n]) << '\n';
    return 0;
}