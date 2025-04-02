#include<bits/stdc++.h>
using namespace std;
const int N=806;
char s[N][N];
bool v1[N][N],v2[N][N];
int n,m,bx,by,gx,gy,px,py,qx,qy;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>(s[i]+1);
        px=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            if(s[i][j]=='M')bx=i,by=j;
            else if(s[i][j]=='G')gx=i,gy=j;
            else if(s[i][j]=='Z')px?tie(qx,qy)=make_tuple(i,j):tie(px,py)=make_tuple(i,j);
        }
        auto pd=[&](int x,int y,int k){return x>0&&x<=n&&y>0&&y<=m&&s[x][y]!='X'&&abs(x-px)+abs(y-py)>2*k&&abs(x-qx)+abs(y-qy)>2*k;};
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        queue<tuple<int,int,int>> q1,q2;
        q1.emplace(bx,by,0);
        q2.emplace(gx,gy,0);
        v1[bx][by]=v2[gx][gy]=1;

        while(!q1.empty()||!q2.empty()){
            if(!q1.empty()){
                auto [x,y,step]=q1.front(); q1.pop();
                if(!pd(x,y,step)) continue;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(pd(nx,ny,step+1)&&!v1[nx][ny]){
                        v1[nx][ny]=1;
                        q1.emplace(nx,ny,step+1);
                    }
                }
            }
            if(!q2.empty()){
                auto [x,y,step]=q2.front(); q2.pop();
                if(!pd(x,y,step)) continue;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(pd(nx,ny,step+1)&&!v2[nx][ny]){
                        if(v1[nx][ny]){ cout<<step+1<<'\n'; goto next_case; }
                        v2[nx][ny]=1;
                        q2.emplace(nx,ny,step+1);
                    }
                }
            }
        }
        cout<<"-1\n";
    next_case:;
    }
}
