#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1210,INF=0x3f3f3f3f;
int n,m,p,q;
ll a[N][N],d[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    int x1,y1,x2,y2,c;
    while(p--){
        cin>>x1>>y1>>x2>>y2>>c;
        d[x1][y1]+=c;
        d[x2+1][y2+1]+=c;
        d[x1][y2+1]-=c;
        d[x2+1][y1]-=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
            a[i][j]+=d[i][j];
            cout<<a[i][j]<<" ";
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
        puts("");
    }
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        cout<<a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]<<"\n";
    }
    return 0;
}