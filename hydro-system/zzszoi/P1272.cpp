#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL f[N];
LL s[N];
int q[N];  
LL g(int i){
    if(i==0)  return 0;
    return f[i-1]-s[i];
}
int main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }
    int hh=0,tt=0;
    for(int i=1;i<=n;i++){
       if(q[hh]<i-k) hh++;
       f[i]=max(f[i-1],g(q[hh])+s[i]);
       while(hh<=tt&&g(q[tt])<=g(i)) tt--;
       q[++tt]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}