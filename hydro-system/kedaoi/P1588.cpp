#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,INF=0x3f3f3f3f;
int n,m,a[N],d[N];
int num[N],st[N],ed[N];

bool check(int t){
    memset(d,0,sizeof(d));
    for(int i=1;i<=t;i++){
        d[st[i]]+=num[i];
        d[ed[i]+1]-=num[i];
    }
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
        if(d[i]>a[i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>num[i]>>st[i]>>ed[i];
    int l=0,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(l==m)cout<<0<<endl;
    else cout<<-1<<endl<<l+1<<endl;
    return 0;
}