#include <bits/stdc++.h>
using namespace std;
using int128 = __int128_t;
static inline void relax(long long A, long long s, long long T, long long &ans)
{
    if (A == 0 || A >= T)
        return;
    long long denom = T - A;
    int128 num = (int128)s * T - 1;
    if (num <= 0)
        return;
    long long Hmax = (long long)(num / denom);
    if (Hmax <= 0)
        return;
    int128 V = (int128)A * Hmax;
    if (V > ans)
        ans = (long long)V;
}
long long solve(const vector<vector<int>> &d, int m, int n, int limW, int limH)
{
    const long long T = 1LL * m * n;
    long long ans = 0;
    for (int top = 0; top < m; ++top)
    {
        vector<int> colMin(n, INT_MAX);
        for (int bottom = top; bottom < m && bottom - top + 1 <= limH; ++bottom)
        {
            for (int j = 0; j < n; ++j)
                colMin[j] = min(colMin[j], d[bottom][j]);
            int h = bottom - top + 1;
            long long A_coeff = h;
            vector<int> L(n), R(n);
            {
                stack<int> st;
                for (int j = 0; j < n; ++j)
                {
                    while (!st.empty() && colMin[st.top()] >= colMin[j])
                        st.pop();
                    L[j] = st.empty() ? -1 : st.top();
                    st.push(j);
                }
            }
            {
                stack<int> st;
                for (int j = n - 1; j >= 0; --j)
                {
                    while (!st.empty() && colMin[st.top()] > colMin[j])
                        st.pop();
                    R[j] = st.empty() ? n : st.top();
                    st.push(j);
                }
            }

            for (int j = 0; j < n; ++j)
            {
                if (colMin[j] <= 0)
                    continue;
                int fullWidth = R[j] - L[j] - 1;
                int w = min(fullWidth, limW);
                if (w <= 0)
                    continue;
                long long A = A_coeff * w;
                relax(A, colMin[j], T, ans);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("drink.in", "r", stdin);
    freopen("drink.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, m, n;
    cin >> a >> b >> m >> n;
    vector<vector<int>> d(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];

    long long ans = 0;
    ans = max(ans, solve(d, m, n, a, b));
    ans = max(ans, solve(d, m, n, b, a));
    cout << ans << '\n';
    return 0;
}
