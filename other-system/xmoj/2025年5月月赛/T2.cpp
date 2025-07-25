#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}
    void update(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int prefix_sum(int idx) const
    {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
    int total() const { return prefix_sum(n); }
    int suffix_sum(int idx) const { return total() - prefix_sum(idx - 1); }
};
int32_t main()
{
    freopen("difficulty.in", "r", stdin);
    freopen("difficulty.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr0, arr1, arr2;
    int C3 = 0, C2 = 0;
    int Xi, Ai, Bi;
    int maxAi = 0, maxBi = 0;
    vector<int> allAi;
    for (int i = 0; i < n; i++)
    {
        cin >> Xi >> Ai >> Bi;
        allAi.push_back(Ai);
        maxAi = max(maxAi, Ai);
        maxBi = max(maxBi, Bi);
        if (Xi == 0)
            arr0.emplace_back(Ai, Bi);
        else if (Xi == 1)
            arr1.emplace_back(Ai, Bi);
        else if (Xi == 2)
        {
            arr2.emplace_back(Ai, Bi);
            C2++;
        }
        else
            C3++;
    }
    int base_n2 = C3 + C2;
    int m2_needed = m - base_n2;
    if (m2_needed <= 0)
    {
        cout << C3 << "\n";
        return 0;
    }
    sort(allAi.begin(), allAi.end());
    allAi.erase(unique(allAi.begin(), allAi.end()), allAi.end());
    allAi.push_back(maxAi + 1);
    sort(allAi.begin(), allAi.end());
    auto cmp_desc = [](const pair<int, int> &a, const pair<int, int> &b)
    { return a.first > b.first; };
    sort(arr0.begin(), arr0.end(), cmp_desc);
    sort(arr1.begin(), arr1.end(), cmp_desc);
    sort(arr2.begin(), arr2.end(), cmp_desc);
    int FT_n = maxBi + 2;
    Fenwick FT_E(FT_n), FT1plus(FT_n), FT2minus(FT_n);
    for (auto &p : arr1)
        FT_E.update(p.second + 1, 1);
    for (auto &p : arr2)
        FT2minus.update(p.second + 1, 1);
    int g1_a_plus = 0, g2_a_plus = 0;
    size_t p0 = 0, p1 = 0, p2 = 0;
    int ans = LLONG_MAX;
    for (int idx = (int)allAi.size() - 1; idx >= 0; --idx)
    {
        int SA = allAi[idx];
        while (p0 < arr0.size() && arr0[p0].first >= SA)
        {
            FT_E.update(arr0[p0].second + 1, 1);
            ++p0;
        }
        while (p1 < arr1.size() && arr1[p1].first >= SA)
        {
            FT_E.update(arr1[p1].second + 1, -1);
            FT1plus.update(arr1[p1].second + 1, 1);
            ++g1_a_plus;
            ++p1;
        }
        while (p2 < arr2.size() && arr2[p2].first >= SA)
        {
            FT2minus.update(arr2[p2].second + 1, -1);
            ++g2_a_plus;
            ++p2;
        }
        int need = m2_needed - g1_a_plus;
        int base_extra3 = (int)C3 + g2_a_plus;
        if (need <= 0)
        {
            ans = min(ans, base_extra3);
            continue;
        }
        int avail = FT_E.total();
        if (need > avail)
            continue;
        int lo = 1, hi = FT_n;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) >> 1;
            int suf = FT_E.total() - FT_E.prefix_sum(mid - 1);
            if (suf >= need)
                lo = mid;
            else
                hi = mid - 1;
        }
        int idxB = lo;
        int g1_cost = FT1plus.suffix_sum(idxB);
        int g2_cost = FT2minus.suffix_sum(idxB);
        ans = min(ans, base_extra3 + (int)g1_cost + (int)g2_cost);
    }
    cout << ans << "\n";
    return 0;
}
