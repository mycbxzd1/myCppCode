#include <iostream>
#define int long long
using namespace std;
const int N = 25, P = 1e9 + 7;
int a[N];
int inv[N];
auto ksm = [](int a, int b) -> int
{int ans = 1;while (b) {if (b & 1) ans = ans * a % P;a = a * a % P;b >>= 1;}return ans; };
int C(int y, int x)
{
    if (y < 0 || x < 0 || y < x)
        return 0;
    y %= P;
    if (y == 0 || x == 0)
        return 1;
    int ans = 1;
    for (int i = 0; i < x; i++)
        ans = ans * (y - i) % P;
    for (int i = 1; i <= x; i++)
        ans = ans * inv[i] % P;
    return ans;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 20; i++)
        inv[i] = ksm(i, P - 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = C(n + m - 1, n - 1);
    for (int x = 1; x < (1 << n); x++)
    {
        int t = n + m, p = 0;
        for (int i = 0; i < n; i++)
            if (x >> i & 1)
                ++p, t -= a[i + 1];
        t -= p + 1;
        if (p & 1)
            ans = (ans - C(t, n - 1)) % P;
        else
            ans = (ans + C(t, n - 1)) % P;
    }
    cout << (ans + P) % P << endl;
    return 0;
}