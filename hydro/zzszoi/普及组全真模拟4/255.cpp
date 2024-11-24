#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int f[N][N];
int a[N],c[N],b[N],tmp,n,k;
int main(){
	//freopen("li.in","r",stdin);
	//freopen("li.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n/2;i++)cin>>a[i];
	for(int i=1;i<=n/2;i++)tmp=a[i],cin>>a[i],a[i]=max(a[i],tmp);
	for(int i=1;i<=n/2;i++)cin>>b[i];
	for(int i=1;i<=n/2;i++)tmp=b[i],cin>>b[i],b[i]+=tmp; 
	memset(f, 0, sizeof(f));
	for(int i=1;i<=n/2;i++)for(int j=1;j<=k;j++)if(j>=1)f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]),j>=2?f[i][j]=max(f[i][j],f[i-1][j-2]+b[i]):0;
	cout<<f[n/2][k];
}

