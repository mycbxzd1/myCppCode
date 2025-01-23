#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
const int mod=200907;
int quickpow(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}
int main(){
    int T;cin>>T;
    while(T--){
        int a,b,c,k;cin>>a>>b>>c>>k;
        if(a == 0 && b == 0 && c == 0) {
            cout << 0 << endl;
            continue;
        }
        if(b-a==c-b) {
            int d = b-a;
            cout << ((1LL * d * (k-1) % mod + a) % mod + mod) % mod << endl;
        }
        else/*if(a != 0 && b != 0 && c != 0 && 1LL * a * c == 1LL * b * b) */{
            int q = b / a;
            cout << (1LL * quickpow(q, k-1, mod) * a % mod + mod) % mod << endl;
        }
    }
    return 0;
}
