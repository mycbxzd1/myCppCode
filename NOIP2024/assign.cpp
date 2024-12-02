#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long ksm(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int n,m;
long long v,ans;
map<int,int>mp;
int main(){
    int T;
    cin>>T;
    while(T--){
        mp.clear();ans=1;
        cin>>n>>m>>v;
        for(int i=0,c,d;i<m;++i){
            cin>>c>>d;
            if(mp.count(c)&&mp[c]!=d){
                ans=0;
                cout<<0<<endl;
                break;
            }
            else mp[c]=d;
        }
        if(ans==0)continue;
        auto last=mp.begin(),next=mp.begin();
        ans=ksm(v,((*next).first-1)*2);
        for(++next;next!=mp.end();++last,++next){
            int it1=last->first,it2=next->first;
            ans=ans*(ksm(v,(it2-it1)*2)-ksm(v,it2-it1-1)*(v-1)%mod+mod)%mod;
        }
        ans=ans*ksm(v,(n-last->first)*2)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
