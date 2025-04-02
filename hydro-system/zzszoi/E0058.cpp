#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> b = arr;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int ans = n * c + d;
        int k = b.size();
        for (int i = 1; i <= k; i++)
        {
            if (b[i - 1] < i)
                continue;
            int cost = c * (n - i) + d * (b[i - 1] - i);
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}
