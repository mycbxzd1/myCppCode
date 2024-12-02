#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int n,m,a[N][N];
int main(){
    cin>>n>>m;
    while(n--){
        int x,y,v;cin>>x>>y>>v;
        a[x+1][y+1]+=v;
    }
    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=m;i<=5001;i++){
        for(int j=m;j<=5001;j++){
            ans=max(ans,a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m]);
        }
    }
    cout<<ans;
    return 0;
}