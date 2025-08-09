#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct Star
{
    double x, y;
} stars[MAXN];
int n, m;

bool cover(int p, double r)
{
    static vector<pair<double, int>> ev;
    ev.clear();
    const double two_pi = 2.0 * pi;
    for (int i = 1; i <= n; ++i)
        if (i != p)
        {
            double dx = stars[i].x - stars[p].x;
            double dy = stars[i].y - stars[p].y;
            double d = hypot(dx, dy);
            if (d > 2.0 * r + 1e-8)
                continue;

            double ang = atan2(dy, dx);
            double t = d / (2.0 * r);
            if (t > 1)
                t = 1;
            if (t < -1)
                t = -1;
            double del = acos(t);

            double l = ang - del;
            double rgt = ang + del;
            l = fmod(l + two_pi, two_pi);
            rgt = l + 2.0 * del;  

            if (rgt < two_pi - 1e-12)
            {
                ev.push_back({l, 1});
                ev.push_back({rgt, -1});
            }
            else
            { 
                ev.push_back({l, 1});
                ev.push_back({two_pi, -1});
                ev.push_back({0.0, 1});
                ev.push_back({rgt - two_pi, -1});
            }
        }
    sort(ev.begin(), ev.end(), [](auto &a, auto &b)
         {
        if (fabs(a.first - b.first) < 1e-12) return a.second > b.second;
        return a.first < b.first; });

    int cur = 1, best = 1;
    for (auto &e : ev)
    {
        cur += e.second;
        if (cur > best)
            best = cur;
    }
    return best >= m;
}

double solve()
{
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 1);
    mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    shuffle(idx.begin(), idx.end(), rng);

    double ans = 3e4;
    for (int p : idx)
    {
        if (!cover(p, ans))
            continue;

        double l = 0, r = ans;
        for (int it = 0; it < 35; ++it)
        {
            double mid = 0.5 * (l + r);
            if (cover(p, mid))
                r = mid;
            else
                l = mid;
        }
        ans = r;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        stars[i].x = xi;
        stars[i].y = yi;
    }
    cout << fixed << setprecision(10) << solve() << '\n';
    return 0;
}
