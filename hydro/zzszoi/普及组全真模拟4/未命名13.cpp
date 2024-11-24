#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], mx[N], ma = 0, j[N], vi = 1, last = 1, ans = 0;

void init() {
    for (int i = 1; i <= n; i++) {
        j[a[i]]++;
        if (j[a[i]] > ma || (j[a[i]] == ma && a[i] > vi)) {
            ma = j[a[i]];
            vi = a[i];
        }
        mx[i] = vi;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();

    for (int i = 1; i <= n; i++) {
        if (a[i] == last) {
            ans++;
        } else {
            last = mx[i - 1];
        }
    }

    cout << ans ;
    return 0;
}

