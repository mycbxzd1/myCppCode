#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;
int qpow(int a, int p = MOD - 2)
{
    long long r = 1, x = a;
    while (p)
    {
        if (p & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return int(r);
}
struct State
{
    vector<int> cnt;
    int pos;
    bool operator==(State const &o) const
    {
        return pos == o.pos && cnt == o.cnt;
    }
};
struct StateHash
{
    size_t operator()(State const &s) const
    {
        size_t h = s.pos;
        for (int x : s.cnt)
        {
            h = h * 13131 + (x + 2);
        }
        return h;
    }
};
int n, k, m;
vector<int> a;
int invk;
unordered_map<State, int, StateHash> dp;
int dfs(State const &s)
{
    if (s.cnt[a[s.pos]] < 0)
        return 0;
    if (s.pos == m)
        return 0;
    auto it = dp.find(s);
    if (it != dp.end())
        return it->second;
    long long ans = 1;
    long long sum_next = 0;
    for (int face = 1; face <= k; face++)
    {
        State t = s;
        int who = a[s.pos];
        t.cnt[who]++;
        for (int j = 0; j < n; j++)
            if (j != who && t.cnt[j] >= 0)
            {
                if (t.cnt[j] == t.cnt[who])
                {
                    t.cnt[who] = -1;
                    break;
                }
            }
        t.pos++;
        sum_next = (sum_next + dfs(t)) % MOD;
    }
    ans = (ans + sum_next * invk) % MOD;
    return dp[s] = int(ans);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    invk = qpow(k);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> m;
        a.resize(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            --a[i];
        }
        invk = qpow(k);
        dp.clear();
        State init;
        init.cnt.assign(n, 0);
        init.pos = 0;
        cout << dfs(init) << "\n";
    }
    return 0;
}
