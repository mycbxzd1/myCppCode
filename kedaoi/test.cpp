#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,INF=0x3f3f3f3f;
int n,k,a[N],f[N];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=a[i];j--){
            f[j]+=f[j-a[i]];
        }
    }
    cout<<(f[k]?f[k]:-1)<<endl;
    return 0;
}