#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
vector<ll> x(32);
int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int t;
        ll v;
        cin >> t >> v;
        if (t == 1)
            x[v]++;
        else
        {
            for (int j = 29; j >= 0; j--)
            {
                int l = 0, r = x[j];
                while (l < r)
                {
                    int mid = (l + r + 1) >> 1;
                    if (((ll)mid << j) <= v)
                        l = mid;
                    else
                        r = mid - 1;
                }
                v -= (ll)r << j;
            }
            cout << (!v ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
