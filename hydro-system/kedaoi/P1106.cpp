#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105, INF = 0x3f3f3f3f;
int n, m, ans = INF;
int r[22], h[22];

void dfs(int i, int v, int s) {
    if (!i) {
        if (v == n) ans = min(ans, s + r[m] * r[m]);
        return;
    }
    if (v >= n) return; // 超额体积剪枝
    if (i < m && n - v > i * (r[i + 1] * r[i + 1] * h[i + 1])) return; // 用不完剪枝
    if (s + r[m] * r[m] >= ans) return; // 最优性剪枝

    for (r[i] = r[i + 1] - 1; r[i] >= i; r[i]--) {
        for (h[i] = h[i + 1] - 1; h[i] >= i; h[i]--) {
            dfs(i - 1, v + r[i] * r[i] * h[i], s + 2 * r[i] * h[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    r[m + 1] = sqrt(n);
    h[m + 1] = n;
    dfs(m, 0, 0);
    cout << ans << endl;
    return 0;
}
