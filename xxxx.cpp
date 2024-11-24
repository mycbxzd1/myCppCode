#include <bits/stdc++.h>
using namespace std;
vector<int> a, res;
vector<vector<int>> tree;

void dfs(int x) {
    if (tree[x].empty()) {
        res.push_back(a[x]);
        return;
    }
    if (tree[x].size() == 1) {
        dfs(tree[x][0]);
        res.push_back(a[x]);
    } else if (tree[x].size() == 2) {
        int l = tree[x][0], r = tree[x][1];
        if (a[r] < a[l]) swap(tree[x][0], tree[x][1]);
        dfs(tree[x][0]);
        res.push_back(a[x]);
        dfs(tree[x][1]);
    } else {
        res.push_back(a[x]);
    }
}

int main() {
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        a.assign(n + 1, 0);
        tree.assign(n + 1, vector<int>());
        
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            tree[u].push_back(v);
        }

        res.clear();
        dfs(1);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}

