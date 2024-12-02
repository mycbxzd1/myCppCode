#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int n,m,a[N];
int main(){
    cin>>n>>m;
    while(m--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type)a[l]+=100,a[r+1]-=100;
        else a[l]--,a[r+1]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(a[i]>0)ans+=3;
        else if(!a[i])ans+=20;
        else ans+=30;
    }
    cout<<ans;
    return 0;
}