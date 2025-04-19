#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N=2e5+10;
int a[N], f[N][2], s[N][2], stk[N], cnt;
signed main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0] = s[0][0] = 1, f[0][1] = s[0][1] = 0;
    stk[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cnt && a[stk[cnt]] >= a[i])
            cnt--;
        stk[++cnt] = i;
        f[i][0] = ((cnt == 1 ? 0 : f[stk[cnt - 1]][0]) + (s[i - 1][1] - (cnt == 1 ? 0 : s[stk[cnt - 1] - 1][1]) + mod) * a[i]) % mod;
        f[i][1] = ((cnt == 1 ? 0 : f[stk[cnt - 1]][1]) + (s[i - 1][0] - (cnt == 1 ? 0 : s[stk[cnt - 1] - 1][0]) + mod) * a[i]) % mod;
        s[i][0] = (s[i - 1][0] + f[i][0]) % mod;
        s[i][1] = (s[i - 1][1] + f[i][1]) % mod;
    }
    cout << (f[n][0] - f[n][1] + mod) * ((n & 1) ? mod - 1 : 1) % mod;
    return 0;
}
