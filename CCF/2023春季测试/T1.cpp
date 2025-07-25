#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        struct weightedData
        {
            int priority = 0;
            int color = 0;
        };
        vector<weightedData> row(n + 1), col(m + 1);
        for (int i = 1, opt, x, c; i <= q; i++)
        {
            cin >> opt >> x >> c;
            if (opt == 0)
                row[x].priority = i, row[x].color = c;
            else
                col[x].priority = i, col[x].color = c;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (col[j].priority > row[i].priority)
                    cout << col[j].color;
                else
                    cout << row[i].color;
                if (j < m) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
