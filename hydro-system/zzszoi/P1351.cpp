#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=1e9+7;
int f[N],inv[N],d[N]={0,0,1,2};
auto ksm=[](int a,int b)->int
{int ans=1;while(b){if(b&1)ans=a*ans%mod;a=a*a%mod;b>>=1;}return ans;};
signed main()
{
    int T;cin>>T;
    f[0]=1;inv[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
        inv[i]=ksm(f[i],mod-2);
    }
    for(int i=4;i<N;i++)
        d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        if(n-m==1)
            cout<<"0\n";
        else if(m==n)
            cout<<"1\n";
        else if(m==0)
            cout<<d[n]<<"\n";
        else
            cout<<f[n]*inv[m]%mod*inv[n-m]%mod*d[n-m]%mod<<"\n";
    }
    return 0;
}
