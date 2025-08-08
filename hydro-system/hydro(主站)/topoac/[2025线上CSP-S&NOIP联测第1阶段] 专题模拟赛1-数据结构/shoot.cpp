#include <bits/stdc++.h>
using namespace std;
const bool fileio = 0;
const string filename = "shoot";
int main()
{
    if (fileio)
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    vector<long long> down(n + 1), up(n + 1);
    for (int i = 1; i <= n; ++i)
        down[i] = (h[i] + 1) / 2;
    up[n] = down[n];
    for (int i = n - 1; i >= 1; --i)
        up[i] = min(h[i], max(down[i], up[i + 1]));
    long long ans = 0, pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (up[i] > pre)
            ans += (up[i] - pre);
        pre = up[i];
    }
    cout << ans << endl;
    return 0;
}