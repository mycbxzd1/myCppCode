#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20005,INF=0x3f3f3f3f;
int n,m,fa[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;//初始化并查集
    while(m--){
        int x,y;scanf("%d%d",&x,&y);//输入边
        fa[find(x)]=find(y);
    }
    int q;cin>>q;
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        puts(find(x)==find(y)?"Yes":"No");
    }
    return 0;
}