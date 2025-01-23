#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
const int N=1010;
long long x[N][N],a,b,k,n,m;
int main(){
    cin>>a>>b>>k>>n>>m;
    x[1][1]=1;
    for(int i=2;i<=k+1;i++){
        for(int j=1;j<=i;j++){
            x[i][j]=(x[i-1][j-1]*b+x[i-1][j]*a)%mod;
        } 
    }
    cout<<x[k+1][m+1];
}