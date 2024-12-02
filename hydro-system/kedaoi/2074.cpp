#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=30005,INF=0x3f3f3f3f;
int head[N],ver[N],nxt[N],tot,a[N];
int n,m,cnt,deg[N],len;
bool v[N];
bitset<N>f[N];
void topsort(){
    queue<int>q;
    for(int i=1;i<=n;i++)if(!deg[i]) q.push(i);
    while(!q.empty()){
        int x=q.front();q.pop();
        a[++len]=x;
        for(int i=head[x];i;i=nxt[i]){
            int y=ver[i];
            if(--deg[y]==0) q.push(y);
            if(deg[y]==0)q.push(y);
        }
    }
}
void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void dfs(int x){
    v[x]=true;++cnt;
    for(int i=head[x];i;i=nxt[i]){
        int y=ver[i];
        if(v[y]) continue;
        dfs(y);
    }

}
int main(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        add(x,y);
        ++deg[y];
    }
    topsort();
    for(int i=n;i>=1;i--){
        int x=a[i];
        //f[x][x]=1;
        for(int j=head[x];j;j=nxt[j]){
            int y=ver[j];
            f[x]|=f[y];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<f[i].count()<<"\n";
    }

    return 0;
}