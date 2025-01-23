#include<bits/stdc++.h>
using namespace std;
const int MAXN=30001;
const int MAXD=201;
int dp[MAXN][MAXD],ans[MAXD],k,w;

void add(int *a,const int *b){
    int carry=0,i;
    for(i=1;i<=a[0]||i<=b[0]||carry;i++){
        a[i]+=b[i]+carry;
        carry=a[i]/10;
        a[i]%=10;
    }
    a[0]=max(a[0],i-1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>k>>w;
    int rem=w%k,div=w/k,maxHighBit=0;
    for(int i=1;i<=rem;i++)maxHighBit+=(1<<(i-1));
    int maxDigit=(1<<k)-1;
    
    if(div==1||(div==2&&rem==0)){
        if(rem==0)maxHighBit=maxDigit;
        int sum=0;
        for(int i=1;i<=maxHighBit;i++)sum+=maxDigit-i;
        cout<<sum;
        return 0;
    }

    for(int i=1;i<=maxDigit-1;i++){
        dp[i][0]=1;
        dp[i][1]=i;
        add(ans,dp[i]);
    }

    for(int i=3;i<=div;i++){
        for(int j=1;j<=maxDigit-i+1;j++){
            add(dp[j],dp[j-1]);
            add(ans,dp[j]);
        }
    }

    for(int j=1;j<=maxDigit-div;j++)add(dp[j],dp[j-1]);
    for(int j=maxDigit-div;j>=max(maxDigit-div-maxHighBit+1,1);j--)add(ans,dp[j]);
    
    for(int i=ans[0];i>=1;i--)cout<<ans[i];
    return 0;
}
