#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
string a;
stack<int> seq;
int ans;
signed main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    auto P = [=](int x)
    {const int inv2 = (MOD + 1) / 2;x %= MOD;return 1LL * (x * ((x + 1) % MOD) % MOD) * inv2 % MOD; };
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> a;
    int n = a.size();
    vector<int> cnt(n + 1, 0), sumP(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] == 40)
            seq.push(i);
        else
        {
            if (!seq.empty())
            {
                int p = seq.top();
                seq.pop();
                int prev = p - 1;
                cnt[i] = 1 + (prev >= 1 ? cnt[prev] : 0);
                if (cnt[i] >= MOD)
                    cnt[i] -= MOD;
                sumP[i] = (P(prev) + (prev >= 1 ? sumP[prev] : 0)) % MOD;
                int contrib = (cnt[i] * P(i) % MOD - sumP[i] + MOD) % MOD;
                ans = ans + contrib;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
