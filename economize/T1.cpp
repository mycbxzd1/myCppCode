#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int a_low, a_high;
    int b_low, b_high;
};
bool check(int x, const vector<Data> &sortedByBHigh, const vector<long long> &preBHigh_low, const vector<long long> &preBHigh_high,
                  const vector<Data> &sortedByBLow, const vector<long long> &preBLow_low, const vector<long long> &preBLow_high,
                  long long totalBLow_low)
{
    int lo = 0, hi = (int)sortedByBHigh.size();
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (sortedByBHigh[mid].b_high < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    int idxA = lo;
    long long sumA = (idxA > 0 ? preBHigh_low[idxA] : 0);
    long long sumA_r1 = (idxA > 0 ? preBHigh_high[idxA] : 0);
    lo = 0, hi = (int)sortedByBLow.size();
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (sortedByBLow[mid].b_low <= x)
            lo = mid + 1;
        else
            hi = mid;
    }
    int countBLow = lo;
    long long sumBLow_r1 = (countBLow > 0 ? preBLow_high[countBLow] : 0);
    int countB = countBLow - idxA;
    long long sumB = sumBLow_r1 - sumA_r1;
    long long sumC = totalBLow_low - preBLow_low[countBLow];
    if (countB <= 0)
        return false;
    long long mCandidate = sumA + sumB + sumC;
    long long k = (mCandidate + 1) / 2;
    return (sumA < k && k <= sumA + sumB);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int c, T;
    cin >> c >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int n;
        cin >> n;
        vector<Data> arr(n);
        int globalB_low_min = INT_MAX, globalB_high_max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].a_low >> arr[i].a_high >> arr[i].b_low >> arr[i].b_high;
            globalB_low_min = min(globalB_low_min, arr[i].b_low);
            globalB_high_max = max(globalB_high_max, arr[i].b_high);
        }
        vector<Data> sortedByBHigh = arr, sortedByBLow = arr;
        sort(sortedByBHigh.begin(), sortedByBHigh.end(), [](const Data &d1, const Data &d2) -> bool
             { return d1.b_high < d2.b_high; });
        sort(sortedByBLow.begin(), sortedByBLow.end(), [](const Data &d1, const Data &d2) -> bool
             { return d1.b_low < d2.b_low; });
        int sz1 = sortedByBHigh.size();
        vector<long long> preBHigh_low(sz1 + 1, 0), preBHigh_high(sz1 + 1, 0);
        for (int i = 0; i < sz1; i++)
        {
            preBHigh_low[i + 1] = preBHigh_low[i] + sortedByBHigh[i].a_low;
            preBHigh_high[i + 1] = preBHigh_high[i] + sortedByBHigh[i].a_high;
        }
        int sz2 = sortedByBLow.size();
        vector<long long> preBLow_low(sz2 + 1, 0), preBLow_high(sz2 + 1, 0);
        for (int i = 0; i < sz2; i++)
        {
            preBLow_low[i + 1] = preBLow_low[i] + sortedByBLow[i].a_low;
            preBLow_high[i + 1] = preBLow_high[i] + sortedByBLow[i].a_high;
        }
        long long totalBLow_low = preBLow_low[sz2];
        auto feasible = [&](int x) -> bool
        {
            return check(x, sortedByBHigh, preBHigh_low, preBHigh_high,
                                sortedByBLow, preBLow_low, preBLow_high,
                                totalBLow_low);
        };
        int Lbound = globalB_low_min, Rbound = globalB_high_max;
        int lo = Lbound, hi = Rbound, ansMin = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid))
            {
                ansMin = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        if (ansMin == -1)
        {
            cout << 0 << "\n";
            continue;
        }
        lo = ansMin;
        hi = Rbound;
        int ansMax = ansMin;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid))
            {
                ansMax = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        int res = ansMax - ansMin + 1;
        cout << res << "\n";
    }
    return 0;
}