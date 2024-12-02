#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 70;
int n, cnt, sum, len, a[MAXN], t, mx;
bool v[MAXN];

bool dfs(int i, int sum, int last) {
    if (i == cnt + 1) return true;
    if (sum == len) return dfs(i + 1, 0, 1);
    int fail = 0;
    for (int j = last; j <= n; j++) {
        if (!v[j] && sum + a[j] <= len && a[j] != fail) {
            v[j] = true;
            if (dfs(i, sum + a[j], j + 1)) return true;
            v[j] = false;
            fail = a[j]; // 剪枝
            if (sum == 0) return false;
            if (sum + a[j] == len) return false;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x <= 50) a[++t] = x, mx = max(mx, x), sum += x;
    }
    n = t;
    sort(a + 1, a + n + 1, greater<int>());
    for (len = mx; len <= sum; len++) { // 枚举长度
        if (sum % len != 0) continue;
        cnt = sum / len;
        memset(v, false, sizeof(v));
        if (dfs(1, 0, 1)) {
            cout << len << endl;
            return 0;
        }
    }
    return 0;
}
