#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
const int MAXX=12;
const int INF=1e8;
int f[MAXN][(1<<MAXX)|1],adj[MAXN][MAXN]; // 修改数组名称为 adj
int total,ans,n,m,x,y,v;
struct node{
	int to,w;
	node(int to=0,int w=0):to(to),w(w){}
	bool operator<(const node&a)const{
		return w<a.w;
	}
};
vector<node> edge[MAXN];
void dfs(int cur,int sum,int stats,int dep,int s,vector<node>&q){
	if(cur==(int)q.size()){
		f[dep][s|stats]=min(f[dep][s|stats],f[dep-1][s]+sum*dep);
		return;
	}
	dfs(cur+1,sum+q[cur].w,stats|(1<<q[cur].to),dep,s,q);
	dfs(cur+1,sum,stats,dep,s,q);
}
int main(){
	cin>>n>>m;
	total=(1<<n)-1;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)adj[i][j]=INF; // 修改为 adj
	for(int i=1;i<=m;++i){
		cin>>x>>y>>v;
		--x,--y;
		adj[x][y]=min(adj[x][y],v); // 修改为 adj
		adj[y][x]=min(adj[y][x],v); // 修改为 adj
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(adj[i][j]!=INF){ // 修改为 adj
				edge[i].push_back(node(j,adj[i][j])); // 修改为 adj
			}
		}
		sort(edge[i].begin(),edge[i].end());
	}
	fill(&f[0][0],&f[MAXN][0],INF);
	for(int i=0;i<n;++i)f[0][1<<i]=0;
	for(int dep=1;dep<n;++dep){
		for(int s=1;s<=total;++s){
			if(f[dep-1][s]>=INF)continue;
			vector<node> q;
			for(int cur=0;cur<n;++cur){
				if(s&(1<<cur))continue;
				for(auto&e:edge[cur]){
					if(s&(1<<e.to)){
						q.push_back(node(cur,e.w));
						break;
					}
				}
			}
			dfs(0,0,0,dep,s,q);
		}
	}
	ans=INF;
	for(int i=0;i<n;++i)ans=min(ans,f[i][total]);
	cout<<ans<<endl;
	return 0;
}
