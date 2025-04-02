#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;

int main(){
    int n,x;cin>>n;
    for(int i=1;i<=n;i++)cin>>x;
    int res=0;
    for(int i=1;i<=n;i++)res^=x;
    if(res)cout<<"win\n";
    else cout<<"lost\n";
    return 0;
}