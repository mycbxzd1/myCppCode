#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,INF=0x3f3f3f3f;
int p[20],n,ans=INF;
void dfs(int now,int cnt){
    if(!now){
        ans=min(ans,cnt);
        return;
    }
    if(cnt>=ans)return;
    for(int i=17;i;i--){
        if(p[i]>now)continue;
        int sum=now/p[i];
        dfs(now%p[i],cnt+sum);
        if(sum>1)dfs(now-p[i]*(sum-1),cnt+sum-1);
    }
}
int main(){
    for(int i=1;i<=17;i++)p[i]=i*i*i*i;
    cin>>n;
    dfs(n,0);
    cout<<ans<<endl;
    return 0;
}