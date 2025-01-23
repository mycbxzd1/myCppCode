#include<bits/stdc++.h>
using namespace std;
#define int long long
int prime,base,number,m;
unordered_map<int,int>mp;
auto ksm=[](int a,int b,int mod){int result=1;while(b){if(b&1)result=result*a%mod;a=a*a%mod;b>>=1;}return result;};
signed main(){
    cin>>prime>>base>>number;
    m=ceil(sqrt(prime));
    for(int i=0,t=number;i<=m;i++,t=t*base%prime)mp[t]=i;
    for(int i=1,tt=ksm(base,m,prime),t=tt;i<=m;i++,t=t*tt%prime){
        if(mp.count(t)){
            cout<<i*m-mp[t] <<"\n";
            return 0;
        }
    }
    cout<<"no solution\n";
    return 0;
}
