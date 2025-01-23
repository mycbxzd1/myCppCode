#include <bits/stdc++.h>
using namespace std;
#define N 11000
#define int long long
const int mod = 10007;
int pw[N], inv[N];
auto C = [](int n, int m) -> int {
    if (n < m) return 0;
    return 1LL * pw[n] * inv[n - m] % mod * inv[m] % mod;
};
int lucas(int n,int m)
{
    if (n<m)return 0;
    int ans=1;
    while (n&&m)
    {
        ans=1LL*ans*C(n%mod,m%mod)%mod;
        n/=mod;
        m/=mod;
    }
    return ans;
}

signed main()
{
    pw[0]=1;
    for (int i=1;i<=mod;i++)
        pw[i]=1LL*pw[i-1]*i%mod;
    inv[1]=1;
    for (int i=2;i<=mod;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    inv[0]=1;
    for (int i=1;i<=mod;i++)
        inv[i]=1LL*inv[i-1]*inv[i]%mod;
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        cout<<lucas(n,m)<<"\n";
    }
    return 0;
}