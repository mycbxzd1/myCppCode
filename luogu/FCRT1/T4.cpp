#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m;
vector<int> R, C, row, col, pow10_row, pow10_col;
int ans = 0;
void dfs(int pos)
{
    if (pos == n * m)
    {
        ans = (ans + 1) % mod;
        return;
    }
    int i = pos / m;
    int j = pos % m;
    for (int d = 0; d <= 9; ++d)
    {
        __int128 newRow = (__int128)row[i] * 10 + d;
        __int128 maxRow = newRow * pow10_row[m - j - 1] + (pow10_row[m - j - 1] - 1);
        if (maxRow > R[i])
            continue;
        __int128 newCol = (__int128)col[j] * 10 + d;
        __int128 maxCol = newCol * pow10_col[n - i - 1] + (pow10_col[n - i - 1] - 1);
        if (maxCol > C[j])
            continue;
        int oldRow = row[i];
        row[i] = (int)newRow;
        int oldCol = col[j];
        col[j] = (int)newCol;
        dfs(pos + 1);
        row[i] = oldRow;
        col[j] = oldCol;
    }
}
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    R.resize(n);
    C.resize(m);
    for (int i = 0; i < n; ++i)
        cin >> R[i];
    for (int j = 0; j < m; ++j)
        cin >> C[j];
    row.assign(n, 0);
    col.assign(m, 0);
    int maxLen = max(n, m);
    pow10_row.assign(maxLen + 1, 1);
    pow10_col.assign(maxLen + 1, 1);
    for (int k = 1; k <= maxLen; ++k)
    {
        pow10_row[k] = pow10_row[k - 1] * 10;
        pow10_col[k] = pow10_col[k - 1] * 10;
    }
    dfs(0);
    cout << ans << '\n';
    return 0;
}
