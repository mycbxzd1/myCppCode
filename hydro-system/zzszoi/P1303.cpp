#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, g[50], w, ans;
vector<int> a;
void dfs1(int k, int sumVal) {
    if (k == 0) {
        a.push_back(sumVal);
        return;
    }
    dfs1(k - 1, sumVal);
    if (sumVal + g[k] <= w) {
        dfs1(k - 1, sumVal + g[k]);
    }
}
void dfs2(int i, int sumVal) {
    if (i > n) {
        int remain = w - sumVal; 
        auto it = upper_bound(a.begin(), a.end(), remain);
        if (it != a.begin()) {
            --it;
            ans = max(ans, sumVal + (*it));
        }
        return;
    }
    dfs2(i + 1, sumVal);
    if (sumVal + g[i] <= w) {
        dfs2(i + 1, sumVal + g[i]);
    }
}

signed main() {
    cin >> w >> n;
    for (int i = 1; i <= n; i++) cin >> g[i];
    
    sort(g + 1, g + n + 1, [](int x, int y){ return x > y; });
    
    int k = min(n / 2, n); 
    
    dfs1(k, 0);
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    dfs2(k + 1, 0);

    cout << ans << endl;
    return 0;
}