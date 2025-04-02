#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int MXE=200010,MXN=2010;
int fac[MXE],inv[MXE],f[MXN];
pair<int,int> a[MXN];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int h,w,n;cin>>h>>w>>n;

    auto ksm=[&](int a,int p){int res=1;while(p){if(p&1)res=res*a%mod;a=a*a%mod;p>>=1;}return res;};
    auto C=[&](int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;};

    fac[0]=inv[0]=1;
    for(int i=1;i<MXE;i++)fac[i]=fac[i-1]*i%mod,inv[i]=ksm(fac[i],mod-2);

    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    a[n+1]=make_pair(h,w);
    sort(a+1,a+n+2);

    for(int i=1;i<=n+1;i++){
        int x=a[i].first,y=a[i].second;
        f[i]=C(x+y-2,x-1);
        for(int j=1;j<i;j++){
            int tmpX=a[j].first,tmpY=a[j].second;
            if(tmpX<=x&&tmpY<=y)f[i]=(f[i]-f[j]*C(x-tmpX+y-tmpY,x-tmpX)%mod+mod)%mod;
        }
    }
    cout<<f[n+1]<<'\n';
}
