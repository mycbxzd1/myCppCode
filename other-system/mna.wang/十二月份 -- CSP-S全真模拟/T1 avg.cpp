#include <bits/stdc++.h>
using namespace std;
int n, ans, a[1001000];
double sum;

int main() {
    freopen("avg.in", "r", stdin);
    freopen("avg.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);

    double curSum = sum;
    for (int i = n; i >= 1; i--) {
        double avg = curSum / i;
        int pos = upper_bound(a + 1, a + i + 1, avg) - a;
        ans = max(ans, i - (pos - 1));
        curSum -= a[i];
    }
    cout << ans;
    return 0;
}
