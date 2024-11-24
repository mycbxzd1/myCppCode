#include<bits/stdc++.h>
using namespace std;

int n, st, maxn;
int a[1001];
int f[1001][1001];

int main() {
    cin >> n >> st >> maxn;
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[0][st] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxn; j++) {
            if (f[i - 1][j] && j + a[i] <= maxn)
                f[i][j + a[i]] = 1;
            if (f[i - 1][j] && j - a[i] >= 0)
                f[i][j - a[i]] = 1;
        }
    }

    for (int i = maxn; i >= 0; i--) {
        if (f[n][i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

