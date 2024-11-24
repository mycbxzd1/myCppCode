#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int n,a[N],cnt[32][2];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            ++cnt[j][a[i]>>j&1];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            ans+=1LL*cnt[j][!(a[i]>>j&1)]*(1<<j);
        }
    }
    cout<<ans<<endl;
    return 0;
}