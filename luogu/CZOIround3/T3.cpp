#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (1LL << 62);
int solve_small(int n, int x, int y, int z, const vector<int> &A, const vector<int> &B, bool equalCost)
{
    vector<int> a = A;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i)
        pos[a[i]] = i;
    int front = 0;
    int dp[2] = {0, INF};
    vector<char> isZero(n, 0);
    for (int step = 0; step < n; ++step)
    {
        int target = B[step];
        int idx = pos[target];
        int dL = (idx - front + n) % n;
        int dR = (n - dL) % n;
        auto countNonZero = [&](int from, int len, int dir)
        {
            int cnt = 0;
            for (int k = 0; k < len; ++k)
                if (!isZero[(from + (dir * k) + n) % n])
                    ++cnt;
            return cnt;
        };
        int nl = countNonZero(front, dL, 1);
        int nr = countNonZero(front, dR, -1);
        int nxt[2] = {INF, INF};
        for (int s = 0; s < 2; ++s)
        {
            int xl = (s ? y : x), xr = (s ? x : y);
            if (dL)
                nxt[s] = min(nxt[s], dp[s] + xl * nl);
            else
                nxt[s] = min(nxt[s], dp[s]);
            if (dR)
                nxt[s] = min(nxt[s], dp[s] + xr * nr);
            int afterSwap = dp[s] + z;
            int xl2 = (s ? x : y), xr2 = (s ? y : x);
            if (dL)
                nxt[1 - s] = min(nxt[1 - s], afterSwap + xl2 * nl);
            else
                nxt[1 - s] = min(nxt[1 - s], afterSwap);
            if (dR)
                nxt[1 - s] = min(nxt[1 - s], afterSwap + xr2 * nr);
        }
        dp[0] = nxt[0];
        dp[1] = nxt[1];
        isZero[idx] = 1;
        front = idx;
    }
    return min(dp[0], dp[1]);
}
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n), b(n);
    for (int &v : a)
        cin >> v;
    for (int &v : b)
        cin >> v;
    cout << solve_small(n, x, y, z, a, b, false) << "\n";
    return 0;
}
