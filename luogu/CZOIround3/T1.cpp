#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, T, x, mx, mi;
int main()
{
    cin >> N >> T >> x;
    int tmp = x * 2 * T;
    mx = min(N, tmp);
    if (x >= 2)
        mi = x;
    else
        mi = min(N, 2LL);
    cout << mx << " " << mi << "\n";
    return 0;
}
