#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("pk.in", "r", stdin);
    freopen("pk.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    int K = lg[n] + 1;
    vector<vector<int>> gcdST(n, vector<int>(K));
    vector<vector<int>> minST(n, vector<int>(K));
    for (int i = 0; i < n; i++) {
        gcdST[i][0] = a[i];
        minST[i][0] = a[i];
    }
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            gcdST[i][j] = gcd(
                gcdST[i][j - 1],
                gcdST[i + (1 << (j - 1))][j - 1]
            );
            minST[i][j] = min(
                minST[i][j - 1],
                minST[i + (1 << (j - 1))][j - 1]
            );
        }
    }
    auto queryGcd = [&](int l, int r) {
        int len = r - l + 1;
        int j = lg[len];
        return gcd(
            gcdST[l][j],
            gcdST[r - (1 << j) + 1][j]
        );
    };
    auto queryMin = [&](int l, int r) {
        int len = r - l + 1;
        int j = lg[len];
        return min(
            minST[l][j],
            minST[r - (1 << j) + 1][j]
        );
    };
    unordered_map<int, vector<int>> pos;
    pos.reserve(n * 2);
    for (int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    for (auto &kv : pos) 
        sort(kv.second.begin(), kv.second.end());
    while (q--) {
        int L, R;
        cin >> L >> R;
        --L; --R; 
        int g = queryGcd(L, R);
        int m = queryMin(L, R);
        int len = R - L + 1;

        int ans;
        if (g != m)
            ans = len;
        else {
            const auto &v = pos[g];
            int cnt = int(upper_bound(v.begin(), v.end(), R)
                        - lower_bound(v.begin(), v.end(), L));
            ans = len - cnt;
        }
        cout << ans << "\n";
    }
    return 0;
}
