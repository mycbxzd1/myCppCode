#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 2e18;
int n, k, q;
vector<vector<int>> a, sum;
vector<int> x, y, ans;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    cin >> n >> k >> q;
    a.assign(k, vector<int>(n + 1));
    sum.assign(k, vector<int>(n + 1, 0));
    for (int row = 0; row < k; ++row) {
        for (int col = 1; col <= n; ++col) {
            cin >> a[row][col];
            sum[row][col] = sum[row][col - 1] + a[row][col];
        }
    }
    x.assign(n + 1, -INF);
    y.assign(n + 1, -INF);
    ans.assign(n + 1, 0);
    x[0] = 0;
    for (int idx = 1; idx <= n; ++idx)
        x[idx] = sum[0][idx];
    ans[1] = x[n];
    for (int grp = 2; grp <= n; ++grp) {
        int layer = (grp - 1) % k;
        int best = -INF;
        fill(y.begin(), y.end(), -INF);
        for (int pos = grp; pos <= n; ++pos) {
            best = max(best, x[pos - 1] - sum[layer][pos - 1]);
            y[pos] = best + sum[layer][pos];
        }
        ans[grp] = y[n];
        x.swap(y);
    }
    while (q--) {
        int m;
        cin >> m;
        cout << ans[m] << '\n';
    }

    return 0;
}
