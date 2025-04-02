#include<bits/stdc++.h>
using namespace std;
int p,q,dp[15][15],a[15];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=9;i++)
        dp[1][i]=1;
    for(int i=2;i<=10;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                if(abs(j-k)>=2)dp[i][j]+=dp[i-1][k];
    auto solve=[&](int x){
        memset(a,0,sizeof a);
        int len=0,ans=0;
        while(x)a[++len]=x%10,x/=10;
        for(int i=1;i<len;i++)
            for(int j=1;j<=9;j++)ans+=dp[i][j];
        for(int i=1;i<a[len];i++)ans+=dp[len][i];
        for(int i=len-1;i>=1;i--){
            for(int j=0;j<a[i];j++)
                if(abs(j-a[i+1])>=2)ans+=dp[i][j];
            if(abs(a[i+1]-a[i])<2)break;
        }
        return ans;
    };
	cin>>p>>q;
	cout<<solve(q+1)-solve(p)<<'\n';
	return 0;
}
