#include <iostream>
#include <vector>
using namespace std;
const int N = 1e7 + 10;
int L, R, n;
int main() {
    cin >> n;
    vector<int> a(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> L >> R;
        a[L] += 1;
        a[R + 1] -= 1;
    }
    //vector<int> p(N, 0);
    int mx = 0;
    for (int i = 1; i < N; ++i) {
        a[i] = a[i - 1] + a[i];
        if (a[i] > mx) mx = a[i];
    }
    int cnt = 0;
    for (int i = 1; i < N; ++i) if (a[i] == mx)cnt++;
    cout << mx << " " << cnt << endl;

    return 0;
}

