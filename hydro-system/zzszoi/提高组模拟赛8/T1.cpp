#include <bits/stdc++.h>
using namespace std;
int n, m, p[20005], s[20005], t[20005], ans;
priority_queue<int, vector<int>, greater<int>> que;
int main()
{
    freopen("pig.in", "r", stdin);
    freopen("pig.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i] >> t[i];
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [=](int x, int y)
         { return s[x] < s[y]; });
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < m && s[idx[j]] <= p[i])
            que.push(t[idx[j]]), j++;
        while (que.size() && que.top() < p[i])
            que.pop();
        if (que.empty())
            continue;
        que.pop();
        ans++;
    }
    cout << ans;
    return 0;
}
