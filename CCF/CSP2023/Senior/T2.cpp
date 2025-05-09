#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2000006;
int n;
char s[MAXN];
int lastPos[MAXN];
int dpCnt[MAXN];
int32_t main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        int j = i - 1;
        while (j > 0 && s[j] != s[i])
            j = lastPos[j] - 1;
        if (j <= 0)
            lastPos[i] = 0;
        else
            lastPos[i] = j, dpCnt[i] = dpCnt[j - 1] + 1, result += dpCnt[i];
    }
    cout << result << "\n";
    return 0;
}
