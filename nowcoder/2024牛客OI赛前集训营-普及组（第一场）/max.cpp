#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, c;
const int N = 1e5 + 10;
int x[N], y[N];
long long solve(int a) {
    int b = c - a;
    long long S_xy = 0, S_x = 0, S_y = 0;
    for (int i = 1; i <= n; i++) {
        S_xy += 1LL * x[i] * y[i];
        S_x += x[i];
        S_y += y[i];
    }
    return S_xy - a * S_y - b * S_x + 1LL * a * b * n;
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> y[i];
    long long max_val = -2147483679;
    int best_a = 0, best_b = 0;
    for (int a = 1; a < c; a++) {
        long long val = solve(a);
        if (val > max_val) {
            max_val = val;
            best_a = a;
            best_b = c - a;
        }
    }
    cout << best_a << " " << best_b << endl;
    return 0;
}
