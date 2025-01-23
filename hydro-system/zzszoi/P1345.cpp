#include <bits/stdc++.h>
using namespace std;
long long n, a[11], b[11], ans, lcm;
long long lcm_two(long long x, long long y) {
    return x * y / __gcd(x, y);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i] >> b[i];
    lcm = a[1], ans = b[1];
    for (int i = 2; i <= n; i++) {
        while (ans % a[i] != b[i])ans += lcm;
        lcm = lcm_two(lcm, a[i]);
    }
    cout << ans << endl;
    return 0;
}