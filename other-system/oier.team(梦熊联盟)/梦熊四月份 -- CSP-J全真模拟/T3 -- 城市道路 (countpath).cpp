#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
inline int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + c - 48;
        c = getchar();
    }
    return flag * x;
}
const int N = 1e6 + 7;
int Mod;
ll fac[N], ifac[N], inv[N], pw[N];
inline ll C(int x, int y) {
    return x < y ? 0 : fac[x] * ifac[y] % Mod *
           ifac[x - y] % Mod;
}
ll qpow(ll x, ll y)
{
    ll ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % Mod;
        y >>= 1, x = x * x % Mod;
    }
    return ret;
}
int main()
{
    int T = 1;
    fac[0] = inv[1] = ifac[0] = pw[0] = 1;
    while (T--)
    {
        int n = read();
        Mod = read();
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % Mod, pw[i] = (pw[i - 1] << 1) % Mod;
        for (int i = 2; i <= n; i++)
            inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
        for (int i = 1; i <= n; i++)
            ifac[i] = ifac[i - 1] * inv[i] % Mod;
        ll ans = 2;
        for (int i = 2; i <= n; i++)
            ans = (ans * 2 % Mod + pw[i - 1] + C(i - 1, i / 2)) % Mod;
        cout<<ans * qpow(qpow(2ll, Mod - 2), n) % Mod<<endl;
    }
}
