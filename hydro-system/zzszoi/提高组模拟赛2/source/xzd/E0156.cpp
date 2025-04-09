#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, mod = 998244353;

int t, n, p[N], stk[N], top, pre[N], f[N], g[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        top = 0;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        f[0] = pre[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            while (top && p[stk[top]] > p[i])
                top--;
            int j = stk[top];
            g[i] = j ? (f[j] + g[j]) % mod : 0;
            f[i] = (pre[i - 1] - (j ? pre[j - 1] : 0) + g[j] + mod) % mod;
            pre[i] = (pre[i - 1] + f[i]) % mod;
            stk[++top] = i;
        }
        cout << (f[n] + g[n]) % mod << "\n";
    }
}
