#include <bits/stdc++.h>
using namespace std;
#define int long long
auto gcd_ = [](int a, int b) -> int
{while (b){int t = a % b;a = b;b = t;}return a; };
signed main()
{
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        if (a > b)
            swap(a, b);
        /* 区间有交集,直接把小的提到大的 */
        if (b - a <= k)
        {
            cout << b << "\n";
            continue;
        }
        /* 区间不相交,尝试枚举 */
        int limit = a + k;
        int ans = (a / gcd_(a, b)) * b; // lcm
        for (int d = 1; d <= limit; ++d)
        {
            int m1 = (a + d - 1) / d;
            int A2 = m1 * d;
            if (A2 > a + k)
                continue;
            int m2 = (b + d - 1) / d;
            int B2 = m2 * d;
            if (B2 > b + k)
                continue;
            int l = (A2 / d) * B2;
            if (l < ans)
                ans = l;
        }
        cout << ans << "\n";
    }
    return 0;
}