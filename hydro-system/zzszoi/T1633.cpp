#include<bits/stdc++.h>
using namespace std;
const int mod = 9901;
long long qpow(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long calc(long long p, long long k) {
    if (k == 0) return 1;
    return (qpow(p, k+1) - 1) * qpow(p-1, mod-2) % mod;
}
int main() {
    long long A, B;
    cin >> A >> B;
    long long res = 1;
    for (long long i = 2; i*i <= A; i++) {
        if (A % i == 0) {
            long long cnt = 0;
            while (A % i == 0) {
                A /= i;
                cnt++;
            }
            res = res * calc(i, cnt*B) % mod;
        }
    }
    if (A > 1) res = res * calc(A, B) % mod;
    cout << res << endl;
    return 0;
}
