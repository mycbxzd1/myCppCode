#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N = 1e7 + 5, mod = 1145141;
int n, q, a[N],ans;
int inv(int x){
    int ans = 1, y = mod - 2;
    while(y){
        if(y & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ans;
}

signed main(){
    cin >> n >> q;
    a[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = 1ll * a[i] * a[i-1] % mod;
    }
    //int ans = 0;
    while(q--){
        int l, r;cin >> l >> r;
        ans = ans ^ (1ll * a[r] * inv(a[l-1]) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
