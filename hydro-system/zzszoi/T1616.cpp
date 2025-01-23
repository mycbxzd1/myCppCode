#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int quickpow(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}
int main(){
    int a,b,m;cin>>a>>b>>m;
    cout<<quickpow(a,b,m)<<endl;
    return 0;
}