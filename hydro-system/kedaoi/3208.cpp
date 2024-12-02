#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005,INF=0x3f3f3f3f;
int n,fa[N];
struct node{int p,d;}a[N];
bool cmp(node a,node b){return a.p>b.p;}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    while(cin>>n){
        int mx_d=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].p>>a[i].d;
            mx_d=max(mx_d,a[i].d);
        }
        for(int i=0;i<=mx_d;i++)fa[i]=i;
        sort(a+1,a+n+1,cmp); 
        int ans=0;
        for(int i=1;i<=n;i++){
            int pos=find(a[i].d);
            if(pos){
                ans+=a[i].p;
                fa[pos]=pos-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}