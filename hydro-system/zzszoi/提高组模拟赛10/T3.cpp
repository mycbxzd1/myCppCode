#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int l, r, w;
};
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    int direct = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int l = a[i] + 1;
        int r = n - b[i];
        if (l > r)
            direct++;
        else
            mp[{l, r}]++;
    }
    vector<Node> segs(mp.size());
    for (auto &p : mp)
        segs.push_back({p.first.first, p.first.second, min(p.second, p.first.second - p.first.first + 1)});
    sort(segs.begin(), segs.end(), [](auto &A, auto &B)
         { return A.r != B.r ? A.r < B.r : A.l < B.l; });
    int m = segs.size();
    vector<int> rights(m);
    for (int i = 0; i < m; ++i)
        rights[i] = segs[i].r;
    vector<int> idx(m, -1);
    for (int i = 0; i < m; ++i)
    {
        int target = segs[i].l - 1;
        auto it = upper_bound(rights.begin(), rights.begin() + i, target);
        if (it != rights.begin())
            idx[i] = int((it - rights.begin()) - 1);
    }
    vector<int> dp(m, 0);
    for (int i = 0; i < m; ++i)
    {
        int include = segs[i].w;
        if (idx[i] != -1)
            include += dp[idx[i]];
        if (i > 0)
            dp[i] = max(dp[i - 1], include);
        else
            dp[i] = include;
    }
    int trust = (m > 0 ? dp[m - 1] : 0);
    cout << n - trust << "\n";
    return 0;
}
