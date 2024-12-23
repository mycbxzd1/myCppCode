#include<bits/stdc++.h>
using namespace std;
int st[2500],cnt=0,g[2500],n,m;
long long dp[20][2000][100];
void init(int a=0,int b=0,int c=0){
    if(c>=n){
        st[++cnt]=a;
        g[cnt]=b;
        return;
    }
    init(a,b,c+1);
    init(a+(1<<c),b+1,c+2);
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=cnt;i++)dp[1][i][g[i]]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            for(int k=1;k<=cnt;k++){
                if(st[j]&st[k])continue;
                if((st[j]<<1)&st[k])continue;
                if(st[j]&(st[k]<<1))continue;
                for(int s=m;s>=g[j];s--)dp[i][j][s]+=dp[i-1][k][s-g[j]];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=cnt;i++)ans+=dp[n][i][m];
    cout<<ans;
    return 0;
}
