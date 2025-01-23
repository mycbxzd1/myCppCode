#include<bits/stdc++.h>
using namespace std;
#define int long long

auto ksm=[](int a,int b,int p)->int{int res=1;while(b){if(b&1)res=res*a%p;a=a*a%p;b>>=1;}return res;};

int C(int n, int m, int p) {
    if (n < m) return 0;
    int res = 1;
    for (int i = 0; i < m; i++) {
        res = res * (n - i) % p * ksm(i + 1, p - 2, p) % p;
    }
    return res;
}

int lucas(int n, int m, int p) {
    if (n < m) return 0;
    if (n == 0 || m == 0) return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;cin >> T;
    while (T--) {
        int n, m, mod;
        cin >> n >> m >> mod;
        cout << lucas(n, m, mod) << "\n";
    }
    return 0;
}
