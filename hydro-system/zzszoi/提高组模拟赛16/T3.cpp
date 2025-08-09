#include <bits/stdc++.h>
using namespace std;
using P = pair<long long, long long>;

vector<long long> produce(long long q, const vector<long long> &cyc)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    for (auto c : cyc)
        pq.emplace(c, c);
    vector<long long> res;
    res.reserve(q);
    while (q--)
    {
        auto [t, c] = pq.top();
        pq.pop();
        res.push_back(t);
        pq.emplace(t + c, c);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long q;
    int n, m;
    cin >> q >> n >> m;
    vector<long long> t(n), d(m);
    for (auto &x : t)
        cin >> x;
    for (auto &x : d)
        cin >> x;
    vector<long long> f = produce(q, t);
    vector<long long> g = produce(q, d);
    sort(f.begin(), f.end());
    sort(g.begin(), g.end(), greater<long long>());
    long long ans = 0;
    for (long long i = 0; i < q; ++i)
        ans = max(ans, f[i] + g[i]);
    cout << ans << '\n';
    return 0;
}
