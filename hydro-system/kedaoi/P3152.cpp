#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,q,a[N],sum[N][105]; // 这里把列的大小改成105，假设m最大是100
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ++sum[i][a[i]];
        for(int j=1;j<=m;j++)sum[i][j]+=sum[i-1][j];
    }
    while(q--){
        int l,r;cin>>l>>r;
        int mx=0,num;
        for(int i=1;i<=m;i++){
            if(sum[r][i]-sum[l-1][i]>mx){
                mx=sum[r][i]-sum[l-1][i];
                num=i;
            }
        }
        cout<<num<<endl; // 每个查询结果输出后换行
    }
    return 0;
}
