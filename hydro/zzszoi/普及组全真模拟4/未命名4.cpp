#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1e7 + 10;
int a[N];
int tmp1[20];
bool cmp(int z, int q) {
    return z > q;
}
signed main() {
    int sum = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x < 10) {
            sum -= x;
            cout << sum << endl;
            continue;
        }
        int cnt = 0, tmp = x, now = 0, mx = -1, mx_d = 0;
        while (tmp > 0) {
            int ls = tmp % 10;
            tmp1[now++] = ls;
            if (ls > mx) {
                mx = ls;
                mx_d = now - 1;
            }
            tmp /= 10;
        }
        for (int j = now - 1; j >= 0; j--) {
            if (j == mx_d) continue;
            cnt = cnt * 10 + tmp1[j];
        }
        sum += cnt - x;
        cout << sum << endl;
    }
}
