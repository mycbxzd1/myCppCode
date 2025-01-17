#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,INF=0x3f3f3f3f;
int prime[N],cnt,phi[N];
bool f[N];
void calc(int n){
    memset(f,0,sizeof(f));
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        if(!f[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
            f[prime[j]*i]=1;
            if(i%prime[j])phi[prime[j]*i]=phi[i]*(prime[j]-1);
            else{
                phi[prime[j]*i]=phi[i]*prime[j];
                break;
            }
        }
    }
}
int main(){
    calc(1200);
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        int n,ans=0;cin>>n;
        for(int j=1;j<=n;j++)ans+=phi[j];
        if(n==1)cout<<0<<endl;
        else cout<<(ans<<1|1)<<"\n";
    }
    return 0;
}