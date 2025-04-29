#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 P = 998244353;
const int64 INV2 = 499122177;
int64 add(int64 a, int64 b)
{
    a += b;
    return a >= P ? a - P : a;
}
int64 sub(int64 a, int64 b)
{
    a -= b;
    return a < 0 ? a + P : a;
}
int64 mul(int64 a, int64 b)
{
    return (int64)((__int128)a * b % P);
}
int64 qpow(int64 a, long long e)
{
    int64 r = 1;
    while (e)
    {
        if (e & 1)
            r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}
pair<int64, int64> fib(long long n)
{
    if (!n)
        return {0, 1};
    auto [f, g] = fib(n >> 1);
    int64 c = mul(f, sub(mul(2, g), f));
    int64 d = add(mul(f, f), mul(g, g));
    return n & 1 ? make_pair(d, add(c, d)) : make_pair(c, d);
}

int main()
{
    freopen("NetherWart.in", "r", stdin);
    freopen("NetherWart.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long t1, t2;
    cin >> n >> t1 >> t2;
    vector<int64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << (a[0] % P) << "\n";
        return 0;
    }
    int64 S0 = 0;
    for (int64 x : a)
        S0 = add(S0, x % P);
    int64 l = a[0] % P, b = a[n - 1] % P, a2 = a[n - 2] % P;
    int64 C1 = add(l, b);                   
    int64 part1 = sub(S0, mul(C1, INV2));
    int64 S1 = add(mul(part1, qpow(3, t1)), mul(C1, INV2));
    auto [F_t, F_t1] = fib(t1);            
    int64 Max = add(mul(F_t, a2), mul(F_t1, b));
    int64 C2 = add(l, Max);
    int64 part2 = sub(S1, mul(C2, INV2));
    int64 S2 = add(mul(part2, qpow(3, t2)), mul(C2, INV2));
    cout << S2 << "\n";
    return 0;
}
