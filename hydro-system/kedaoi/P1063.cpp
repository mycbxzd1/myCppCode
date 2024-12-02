#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int cnt[26],ans=1e9;
int main(){
    string s;cin>>s;
    int l=0,r=-1,sum=0;
    int n=s.size();
    while(1){
        while(r+1<n&&sum<26)if(++cnt[s[++r]-'a']==1)sum++;
        if(sum!=26)break;
        ans=min(ans,r-l+1);
        if(!--cnt[s[l++]-'a'])sum--;
    }
    cout<<ans<<endl;
    return 0;
}