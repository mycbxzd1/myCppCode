/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ad.in", "r", stdin);
    freopen("ad.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long best = numeric_limits<long long>::max();
    if (n <= 10)
    {
        int total = 1 << n;
        for (int mask = 0; mask < total; mask++)
        {
            long long curMin = numeric_limits<long long>::max(), curMax = numeric_limits<long long>::min();
            for (int i = 0; i < n; i++)
            {
                long long val = ((mask >> i) & 1) ? (arr[i] + K) : (arr[i] - K);
                curMin = min(curMin, val);
                curMax = max(curMax, val);
            }
            best = min(best, curMax - curMin);
        }
        cout << best << "\n";
    }
    else if (K == 1)
    {
        vector<pair<long long, int>> candidates;
        candidates.reserve((size_t)n * 2);
        for (int i = 0; i < n; i++)
        {
            candidates.push_back({arr[i] - 1, i});
            candidates.push_back({arr[i] + 1, i});
        }
        sort(candidates.begin(), candidates.end(), [](const pair<long long, int> &a, const pair<long long, int> &b)
             { return a.first < b.first; });
        vector<int> freq(n, 0);
        int totalCovered = 0, left = 0;
        for (int right = 0; right < (int)candidates.size(); right++)
        {
            int idx = candidates[right].second;
            freq[idx]++;
            if (freq[idx] == 1)
                totalCovered++;
            while (totalCovered == n)
            {
                best = min(best, candidates[right].first - candidates[left].first);
                int lIdx = candidates[left].second;
                freq[lIdx]--;
                if (freq[lIdx] == 0)
                    totalCovered--;
                left++;
            }
        }
        cout << best << "\n";
    }
    else if (n <= 100 && K != 1)
    {
        vector<long long> candidates;
        for (int i = 0; i < n; i++)
        {
            candidates.push_back(arr[i] - K);
            candidates.push_back(arr[i] + K);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int m = candidates.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                long long L = candidates[i], R = candidates[j];
                bool valid = true;
                for (int k = 0; k < n; k++)
                {
                    long long opt1 = arr[k] - K, opt2 = arr[k] + K;
                    if (!((opt1 >= L && opt1 <= R) || (opt2 >= L && opt2 <= R)))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    best = min(best, R - L);
            }
        }
        cout << best << "\n";
    }
    else
        throw runtime_error("Zhide Xu did not write about this situation");
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ad.in", "r", stdin);
    freopen("ad.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long ans = arr[n - 1] - arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        long long small = min(arr[0] + K, arr[i + 1] - K);
        long long large = max(arr[n - 1] - K, arr[i] + K);
        ans = min(ans, large - small);
    }
    cout << ans << endl;
    return 0;
}
