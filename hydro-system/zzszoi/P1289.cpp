#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[21][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    f[0][0] = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++) {
            f[i+1][j+1] += f[i][j];
            f[i+1][0] += f[i][j] * 9;
        }
        f[i+1][3] += f[i][3] * 10; 
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m = 3;
        cin >> n;
        while (f[m][3] < n) ++m;
        for (int i = m, k = 0; i > 0; i--) {
            for (int j = 0; j <= 9; j++) {
                ll cnt = f[i-1][3];
                if (j == 6 || k >= 3) {
                    int need = max(3 - k - (j == 6), 0);
                    for (int l = need; l < 3; l++)
                        cnt += f[i-1][l];
                }
                if (cnt < n) {
                    n -= cnt;
                } else {
                    if (k < 3) {
                        if (j == 6) {
                            k++;
                        } else {
                            k = 0;
                        }
                    }
                    cout << j;
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}