#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &e : a)
        cin >> e;
    unordered_map<long long, int> mp;
    long long tmp = (long long)4e18;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > tmp)
            mp[a[i]]++;
        if (a[i] < tmp)
            tmp = a[i];
    }
    long long ans = 1;
    for (auto &e : mp)
        ans = ans * (e.second + 1) % mod;
    cout << ans % mod << "\n";
    return 0;
}
