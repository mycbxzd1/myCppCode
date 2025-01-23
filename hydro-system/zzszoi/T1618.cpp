#include<bits/stdc++.h>
using namespace std;
const long long mod = 100003;
long long n, m;
auto ksm = [](long long a) {return (a * a) % mod;};
long long qmi(long long a, long long b) {
    if(b == 0) return 1;
    return (b & 1) ? ksm(qmi(a, b >> 1)) * (a % mod) % mod : ksm(qmi(a, b >> 1));
}
int main(){
    cin >> m >> n;
    long long ans = qmi(m, n) - (m % mod) * qmi(m - 1, n - 1) % mod;
    while (ans < 0)ans += mod;
    cout << (ans + mod) % mod;
    return 0;
}