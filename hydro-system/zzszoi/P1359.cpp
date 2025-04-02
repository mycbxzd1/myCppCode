#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const double Dinf=1e18,eps=1e-6;
int x[N],y[N],w[N],n;
double dist[N];
bool st[N];
int main(){
    auto calc=[&](int a,int b){return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));};
    auto check=[&](double mid){fill(dist,dist+n+1,Dinf);memset(st,0,sizeof st);dist[1]=0;double ans=0;for(int i=1;i<=n;i++){int t=-1;for(int j=1;j<=n;j++)if(!st[j]&&(t==-1||dist[j]<dist[t]))t=j;st[t]=1,ans+=dist[t];for(int j=1;j<=n;j++)if(!st[j]&&dist[j]>abs(w[t]-w[j])-mid*calc(t,j)+eps)dist[j]=abs(w[t]-w[j])-mid*calc(t,j);}return ans>=0.0;};
    cin.tie(0)->sync_with_stdio(0);
    while(cin>>n,n){
        for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>w[i];
        double l=0,r=1e7;
        while(r-l>eps){
            double mid=(l+r)/2;
            if(check(mid))l=mid;
            else r=mid;
        }
        cout<<fixed<<setprecision(2)<<l<<'\n';
    }
}
