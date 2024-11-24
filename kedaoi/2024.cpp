#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int head[N],ver[N],nxt[N],tot,a[N];
int n,m,cnt,deg[N],len;
bool v[N];
bitset<N>f[N];
void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void dfs(int x){
    
}
int main(){
    
    return 0;
}