#include<bits/stdc++.h>
using namespace std;
const int N=100002,M=200002;
int ver[M],edge[M],nxt[M],head[N],out[N],deg[N],n,m,tot;
double dis[N];
queue<int>q;int main(){
    cin>>n>>m;q.push(n);
    auto add = [&](int x,int y,int z)->void{ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;};
    
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        add(y,x,z),deg[x]++;out[x]++;
    }
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nxt[i]){
            int y=ver[i];
            dis[y]+=(dis[x]+edge[i])/deg[y];
            out[y]--;
            if(out[y]==0)q.push(y);
        }
    }
    cout<<fixed<<setprecision(2)<<dis[1]<<endl;
    return 0;
}
