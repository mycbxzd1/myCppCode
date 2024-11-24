#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int k,ans,s[N],a[N],cnt[N],n;
int C(int n,int k){
    ll ans=1;
    for(int i=0;i<k;i++)ans*=n-i;
    for(int i=1;i<=k;i++)ans/=i;
    return ans;
}
void dfs(int i,int sum,int tot){
    if(sum==k){
        ans+=tot;
        return;
    }
    if(sum>k)return;
    if(sum+s[i]<k)return;
    if(i==n+1)return;
    for(int j=0;j<=cnt[i];j++){
        int num=C(cnt[i],j);
        dfs(i+1,sum+j*a[i],tot*num);
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    int t=1;
    cnt[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[t])a[++t]=a[i],cnt[t]=1;
        else cnt[t]++;
    }
    n=t;
    for(int i=n;i>=1;i--)s[i]=a[i]*cnt[i]+s[i+1];
    dfs(1,0,1);
    cout<<(ans?ans:-1)<<endl;
    return 0;
}
/*
动态规划:
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,INF=0x3f3f3f3f;
int n,k,a[N],f[N];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=a[i];j--){
            f[j]+=f[j-a[i]];
        }
    }
    cout<<(f[k]?f[k]:-1)<<endl;
    return 0;
}

*/