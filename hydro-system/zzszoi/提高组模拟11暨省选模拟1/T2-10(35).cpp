#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
static const int MAXK = 5000;
static const int MAXN = 5000;
static int rowMin[MAXK];
signed main()
{
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int k, n, q;
    cin >> k >> n >> q;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int A, B, C;
    cin >> A >> B >> C;
    if (k == 1)
    {
        auto &row = a[0];
        vector<int> prevSmaller(n), nextSmaller(n), stk(n);
        int top = 0;
        for (int i = 0; i < n; i++)
        {
            while (top > 0 && row[stk[top - 1]] >= row[i])
                top--;
            prevSmaller[i] = (top > 0 ? stk[top - 1] : -1);
            stk[top++] = i;
        }
        top = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (top > 0 && row[stk[top - 1]] > row[i])
                top--;
            nextSmaller[i] = (top > 0 ? stk[top - 1] : n);
            stk[top++] = i;
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int ans = 0;
            for (int i = l; i <= r; i++)
            {
                int L = max(prevSmaller[i] + 1, l);
                int R = min(nextSmaller[i] - 1, r);
                int leftCnt = i - L + 1;
                int rightCnt = R - i + 1;
                if (leftCnt > 0 && rightCnt > 0)
                {
                    int M = row[i];
                    int F = A ^ (B * M + C);
                    ans += F * leftCnt * rightCnt;
                }
            }
            cout << ans << '\n';
        }
    }
    else
    {
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int ans = 0;
            for (int x = l; x <= r; x++)
            {
                for (int i = 0; i < k; i++)
                    rowMin[i] = LLONG_MAX;
                for (int y = x; y <= r; y++)
                {
                    int M = LLONG_MIN;
                    for (int i = 0; i < k; i++)
                    {
                        int v = a[i][y];
                        if (v < rowMin[i])
                            rowMin[i] = v;
                        if (rowMin[i] > M)
                            M = rowMin[i];
                    }
                    int F = A ^ (B * M + C);
                    ans += F;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
