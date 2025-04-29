#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1), f(n + 1), s(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 2; i <= n; ++i)
            s[i] = s[i - 1] + (a[i] == a[i - 1] ? a[i] : 0);
        unordered_map<ll, int> last;
        last.reserve(n * 2);

        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1];
            auto it = last.find(a[i]);
            if (it != last.end()) {
                int prev = it->second + 1;
                f[i] = max(f[i], f[prev] + a[i] + s[i] - s[prev]);
            }
            last[a[i]] = i;
        }

        cout << f[n] << "\n";
    }
    return 0;
}
