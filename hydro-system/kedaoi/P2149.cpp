#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=100005;

int n, ans;
int phi[N];

void euler(int n) {
    for(int i=2; i<=n; i++) phi[i] = i;
    for(int i=2; i<=n; i++) {
        if(phi[i]==i) { // 找到一个质数
            for(int j=i; j<=n; j+=i) // 这个质数的1~n/i倍都含有i这个质因子
                phi[j] = phi[j] / i * (i-1);
        }
    }
}

int main() {
    euler(10000);
    cin >> n;
    ans = 3;
    for(int y=2; y<=n; y++) ans += 2*phi[y];
    cout << ans << endl;
    return 0;
}
