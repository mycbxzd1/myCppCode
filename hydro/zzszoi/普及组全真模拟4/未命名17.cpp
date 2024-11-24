#include<bits/stdc++.h>
using namespace std;
const int N = 550;
int dp[110][N][N], t[110], e[110], d[110], r[1000];
int n, m, cnt = 0, mx = 0;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> m;
    for (int i = 2; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> e[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) {
        m -= t[i];
        if (d[i] == 0) for (int j = 0; j < m; j++)r[++cnt] = e[i];
        else for (int j = e[i]; j > 0; j -= d[i])r[++cnt] = j;
        sort(r + 1, r + 1 + cnt, greater<int>);
        int sum = 0;
        for (int j = 1; j <= min(m, cnt); j++)sum += r[j];
        mx = max(mx, sum);
    }
    cout << mx << endl;
}

