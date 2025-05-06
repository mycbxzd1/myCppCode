#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("min.in", "r", stdin);
    freopen("min.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<int, int>> sum(n + 1);
    sum[0] = {0, 0};
    for (int k = 1; k <= n; ++k)
        sum[k].first = sum[k - 1].first + a[k - 1], sum[k].second = k;
    sort(sum.begin(), sum.end());
    int minum = LLONG_MAX / 2;
    for (int i = 1; i <= n; ++i)
        minum = min(minum, llabs(sum[i].first - sum[i - 1].first));
    int mxlen = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (llabs(sum[i].first - sum[i - 1].first) == minum)
        {
            int st = sum[i - 1].second, ed = sum[i].second;
            for (int j = i; j + 1 <= n && sum[j + 1].first == sum[i - 1].first; j++)
                ed = max(ed, sum[j + 1].second);
            mxlen = max(mxlen, llabs(ed - st));
        }
    }
    cout << minum << "\n"
         << mxlen << "\n";
    return 0;
}
