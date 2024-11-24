#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int n,a[N],sum[N],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int mn=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,sum[i]-mn);
        mn=min(mn,sum[i]);
    }
    cout<<ans;
    return 0;
}