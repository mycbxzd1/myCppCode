#include<bits/stdc++.h>
using namespace std;

const int N=210;
int n,l,k,a[N];
double p[N],f[N][N][N<<1],sum;
int main(){
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++)cin>>p[i],p[i]/=100.0;
    for(int i=1;i<=n;i++)cin>>a[i];
    auto calc=[&](int x){return min(x,n)+N;};
    f[0][0][calc(k)]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            for(int h=1-i;h<=n;h++)
                f[i][j][calc(h+a[i])]+=f[i-1][j-1][calc(h)]*p[i],f[i][j-1][calc(h)]+=f[i-1][j-1][calc(h)]*(1-p[i]); 
    for(int i=l;i<=n;i++)
        for(int j=0;j<=n;j++)
            sum+=f[n][i][calc(j)];
    cout<<fixed<<setprecision(6)<<sum<<endl;
    return 0;
}
