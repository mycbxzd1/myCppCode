#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 15;
int mask[maxn], cnt[16], ans;
vector<int> types;
int states;
signed main()
{
    freopen("grass.in", "r", stdin);
    freopen("grass.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            mask[x] |= (1 << i);
        }
    }
    for (int i = 1; i <= n; i++)
        cnt[mask[i]]++;

    for (int s = 1; s < (1 << m); s++)
        if (cnt[s])
            types.push_back(s);

    if (cnt[0])
        ans = 1;
    states = types.size();
    auto check = [&](int s) -> bool
    {
        for (int i = 0; i < states; i++)
        {
            if (!(s & (1 << i)))
                continue;
            for (int j = i + 1; j < states; j++)
            {
                if (!(s & (1 << j)))
                    continue;
                if ((types[i] & types[j]) == 0)
                    return false;
            }
        }
        return true;
    };
    auto calc = [&](int s) -> int
    {
        int sum = 0;
        for (int i = 0; i < states; i++)
            if (s & (1 << i))
                sum += cnt[types[i]];

        return sum;
    };
    for (int s = 1; s < (1 << states); s++)
        if (check(s))
            ans = max(ans, calc(s));

    cout << ans;
    return 0;
}
