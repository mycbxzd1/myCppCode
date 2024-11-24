#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N][N],sum[N][N],m,n,ans;
char op;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)cin>>op,a[i][j]=op=='.'?0:1; 
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];//二位前缀和 
	for(int i=n;i<=m;i++)for(int j=n;j<=m;j++)ans=max(ans,sum[i][j]-sum[i-n][j]-sum[i][j-n]+sum[i-n][j-n]);
	cout<<ans;
}
