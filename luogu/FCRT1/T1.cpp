#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
unordered_map<int, int> mp;
int handle(int x)
{
    if (x < 4)
        return 0;
    auto it = mp.find(x);
    if (it != mp.end())
        return it->second;
    int l = x / 2;
    int r = x - l;
    int ans = 1 + handle(l) + handle(r);
    mp[x] = ans;
    return ans;
}
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 2)
        cout << 1 << endl;
    else
        cout << (handle(n - 1) + 2) << endl;
    return 0;
}
