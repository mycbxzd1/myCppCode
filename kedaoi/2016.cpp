#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin >> t;
    for (int i = 0; i < t; ++i) {
        double H, h, D;
        cin >> H >> h >> D;
        double ans = D - h * D / H;
        double val = sqrt((H - h) * D);
        if (ans <= val && D > val) ans = D + H - 2 * val;
        else if (val < ans) ans = h * D / H;
        else ans = h;
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
