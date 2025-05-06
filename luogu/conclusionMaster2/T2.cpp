#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> diff(n + 2, 0);
    for (int d = 1; d <= n; ++d)
    {
        int m = n / d;
        for (int s = 2; s <= 2 * m; ++s)
        {
            int p = d * s;
            int k = __builtin_popcount(p);
            int a = s - k, b = k;
            if (a < 1 || a > b || b > m)
                continue;
            if (__gcd(a, b) != 1)
                continue;
            int pos = b * d;
            if (a < b)
                diff[pos] += 2;
            else
                diff[pos] += 1;
        }
    }
    long long ans = 0, cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        cur += diff[i];
        ans ^= cur;
    }

    cout << ans << "\n";
    return 0;
}
