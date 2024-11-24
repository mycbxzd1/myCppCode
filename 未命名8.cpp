#include<bits/stdc++.h>
using namespace std;
int v[15],dp[100005][15],a[int(5e5+10)];
int p10[15]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main(){
	int l;cin>>l;
	for(int i=0;i<l;i++)cin>>a[i+1];
	int s=l;
	for(int i=l;i>=1;i--){
		for(int j=1;j<=min(9LL,(long long)l-i+1);j++){
			dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]+1-p10[j-1]*a[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=9;i++)ans=max(ans,dp[1][i]);
	cout<<s-ans<<endl;
}

