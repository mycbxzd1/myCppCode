#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int ans;
void dfs(int x[5],int step=0,char op=0,int tmp=0){
    if(step==5&&tmp==24)ans++;
    if(step==0){
        dfs(x,1,'+');
        dfs(x,1,'-');
    }
    if(op=='+'){
        dfs(x,step+1,'+',tmp+x[step]);
        dfs(x,step+1,'-',tmp+x[step]);
    }
    else{
        dfs(x,step+1,'+',tmp-x[step]);
        dfs(x,step+1,'-',tmp-x[step]);
    }
}
int main(){
    int a,b,c,d,T;cin>>T;
    while(T--){
        ans=0;int x[5];
        cin>>a>>b>>c>>d;
        x[1]=a;x[2]=b;x[3]=c;x[4]=d;
        dfs(x);
        if(ans!=0)cout<<3;
        else cout<<-1;
    }
    return 0;
}