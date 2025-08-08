#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shoot3.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> h(n + 1), L(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    auto hlf = [&](long long x)
    { return (x + 1) / 2; };

    for (int i = 1; i <= n; ++i)
        L[i] = hlf(h[i]);

    r[n] = L[n];
    for (int i = n - 1; i >= 1; --i)
    {
        long long need = r[i + 1];
        long long lo = L[i], hi = h[i];
        // r[i] = min(hi, max(lo, need));
        r[i] = min(hi, max(lo, need));
    }

    long long T = 0, prev = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (r[i] > prev)
            T += (r[i] - prev);
        prev = r[i];
    }
    cout << T << "\n";
    return 0;
}
