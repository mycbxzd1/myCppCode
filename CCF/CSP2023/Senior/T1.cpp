#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 8 + 5;
int n, cnt;

bool check(int a, int b, int c, int d, int e, const auto &locks)
{
    auto minus_diff = [](int k, int t)
    { return k < t ? k - t + 10 : k - t; };
    for (int k = 0; k < n; ++k)
    {
        auto [la, lb, lc, ld, le] = locks[k];
        int f1 = 0;
        if (b == lb && c == lc && d == ld && e == le)
            ++f1;
        if (a == la && c == lc && d == ld && e == le)
            ++f1;
        if (a == la && b == lb && d == ld && e == le)
            ++f1;
        if (a == la && b == lb && c == lc && e == le)
            ++f1;
        if (a == la && b == lb && c == lc && d == ld)
            ++f1;

        int f2 = 0;
        if (minus_diff(a, la) == minus_diff(b, lb) && c == lc && d == ld && e == le)
            ++f2;
        if (minus_diff(b, lb) == minus_diff(c, lc) && a == la && d == ld && e == le)
            ++f2;
        if (minus_diff(c, lc) == minus_diff(d, ld) && a == la && b == lb && e == le)
            ++f2;
        if (minus_diff(d, ld) == minus_diff(e, le) && a == la && b == lb && c == lc)
            ++f2;
        if (f1 != 1 && f2 != 1)
            return false;
    }
    return true;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    vector<tuple<int, int, int, int, int>> locks(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        locks[i] = make_tuple(a, b, c, d, e);
    }
    for (int a = 0; a < 10; ++a)
        for (int b = 0; b < 10; ++b)
            for (int c = 0; c < 10; ++c)
                for (int d = 0; d < 10; ++d)
                    for (int e = 0; e < 10; ++e)
                        if (check(a, b, c, d, e, locks))
                            ++cnt;
    cout << cnt << '\n';
    return 0;
}
