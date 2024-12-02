#include<bits/stdc++.h>
using namespace std;
const int N=50010;
const int mod=1e9+7;
int dp[N][410],ans;
void judge(int n){
	dp[1][1]=1;
    for(int i=1;i<=n;i++)for(int j=1;j<min(400,i);j++)dp[i][j]=(dp[i-j][j]+dp[i-j][j-1])%mod;
	for(int i=1;i<=400;i++)ans+=dp[n][i],ans%=mod; 
} 
int main(){
	
	for(int i=40000;i<=50000;i++){
		judge(i); 
		cout<<ans<<",";
	} 
	
    
}
