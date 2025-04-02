#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int l, r, c[N][N];
int main()
{
    auto solve = [](int x)
    {
        vector<int> num;
        while (x)
            num.push_back(x % 2), x /= 2;
        int n = num.size(), res = 0, last = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                continue;
            if (num[i])
                for (int j = max((n + 1) / 2 - (last + 1), 0); j <= i; j++)
                    res += c[i][j];
            else
                last++;
            if (!i && last >= (n + 1) / 2)
                res++;
        }
        for (int i = 1; i < n; i++)
            for (int j = (i + 1) / 2; j < i; j++)
                res += c[i - 1][j];
        return res + 1;
    };
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            c[i][j] = !j ? 1 : c[i - 1][j] + c[i - 1][j - 1];
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}
