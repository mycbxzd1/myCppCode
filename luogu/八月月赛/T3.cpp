#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << 1 << ' ' << 0 << '\n';
            continue;
        }
        vector<char> used(n + 1, 0);
        int maxk = 0;
        while ((1LL << (maxk + 1)) <= n)
            ++maxk;
        for (int k = maxk; k >= 0; --k)
        {
            int L = 1 << k;
            int R = min(n, (1 << (k + 1)) - 1);
            if (L > R)
                continue;
            int mask = (1 << (k + 1)) - 1;
            for (int x = R; x >= L; --x)
            {
                if (used[x])
                    continue;
                int y = mask ^ x;
                if (y >= 0 && y <= n && !used[y])
                {
                    cout << 2 << ' ' << x << ' ' << y << '\n';
                    used[x] = used[y] = 1;
                }
            }
        }
        if (!used[0])
        {
            cout << 1 << ' ' << 0 << '\n';
            used[0] = 1;
        }
    }
    return 0;
}
