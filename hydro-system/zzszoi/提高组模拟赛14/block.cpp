#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100100;
int n, m;
int h[N];
int pre[N];
int le[N], rg[N];
bool check(int H)
{
    for (int i = n, p = n; i >= 1; --i)
    {
        while (p >= 1 && H - h[p] + p > i)
            --p;
        le[i] = p;
    }
    for (int i = 1, q = 1; i <= n; ++i)
    {
        while (q <= n && h[q] + q - H < i)
            ++q;
        rg[i] = q;
    }
    int best = LLONG_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int L = le[i], R = rg[i];
        if (L < 1 || R > n)
            continue;
        int left_l = H - (i - L);
        int left_r = H;
        int leftSum = 0;
        if (left_l <= left_r)
            leftSum = (left_l + left_r) * (left_r - left_l + 1) / 2;
        int right_l = H - (R - i);
        int right_r = H;
        int rightSum = 0;
        if (right_l <= right_r)
            rightSum = (right_l + right_r) * (right_r - right_l + 1) / 2;
        int total = leftSum + rightSum - H;
        total -= (pre[R] - pre[L - 1]);
        best = min(best, total);
    }
    return best <= m;
}
int32_t main()
{
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        pre[i] = pre[i - 1] + h[i];
    }
    int left = 0, right = 0;
    for (int i = 1; i <= n; ++i)
        left = max<int>(left, h[i]);
    right = left + m;
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }
    cout << left;
    return 0;
}