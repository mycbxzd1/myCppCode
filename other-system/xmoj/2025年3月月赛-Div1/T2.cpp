#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> dp(N+1,vector<int>(2*N+1,0));
    
    for(int i=1;i<=2*N;i++)dp[1][i]=1;
    
    for(int i=2;i<=N;i++){
        for(int j=1;j<=2*N;j++){
            int L=(i==1)?N:(i-1);
            int R=(i==N)?1:(i+1);
            for(int k=1;k<=2*N;k++){
                if(k-L<j&&j<k+R)dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=2*N;i++)ans=(ans+dp[N][i])%MOD;
    cout<<ans<<endl;
    return 0;
}
