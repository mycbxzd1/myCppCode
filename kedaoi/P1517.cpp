#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
ll inv[N],n,p;
int main(){
    cin>>n>>p;inv[1]=1;cout<<1<<endl;
    for(int i=2;i<=n;i++){
        inv[i]=1ll*(p-p/i)*inv[p%i]%p;
        cout<<inv[i]<<endl;
    }
}