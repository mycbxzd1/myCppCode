#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20005,INF=0x3f3f3f3f;
int n,m,fa[N];
int sz[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;//初始化
    while(m--){
        int x,y;
        char s[2];scanf("%s%d",s,&x);x=find(x);
        if(s[0]=='M'){
            scanf("%d",&y);
            y=find(y);
            if(x!=y)fa[x]=y,sz[y]+=sz[x];
        }
        else cout<<sz[x]<<endl;
    }
    /*
    int q;cin>>q;
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        puts(find(x)==find(y)?"Yes":"No");
    }*/
    return 0;
}