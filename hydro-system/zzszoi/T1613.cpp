#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long n, M, f[maxn], q[maxn], a[maxn], s[maxn];
long long X(int i, int j){return s[j] - s[i];}
long long Y(int i, int j){return f[j] + s[j] * s[j] - (f[i] + s[i] * s[i]);}
long long DP(int i, int j){return (s[i] - s[j]) * (s[i] - s[j]) + M + f[j];}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> M) {
        for (int i = 0; i <= n; ++i) {
            a[i] = s[i] = q[i] = f[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            s[i] = a[i] + s[i - 1];
        }
        int l = 0, r = 0;
        q[++r] = 0;
        for (int i = 1; i <= n; ++i) {
            while (l + 1 < r && Y(q[l + 1], q[l + 2]) <= X(q[l + 1], q[l + 2]) * 2ll * s[i])++l;
            f[i] = DP(i, q[l + 1]);
            while (l + 1 < r && Y(q[r - 1], q[r]) * X(q[r], i) >= X(q[r - 1], q[r]) * Y(q[r], i))--r;
            q[++r] = i;
        }
        cout << f[n] << endl;
    }
    return 0;
}
