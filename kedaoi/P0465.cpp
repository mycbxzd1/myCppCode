#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int arr[N];
int temp[N];
int res = 0;
int mrgS(int s[], int l, int m, int r) {
    int i = l, j = m;
    int idx = 0;
    int sum = 0;
    int cnt = 0;
    while (i < m && j <= r) {
        if (s[i] > s[j]) {
            temp[idx++] = s[j++];
            cnt++;
        }
        if (s[i] <= s[j] || j == r + 1) {
            sum += cnt * (m - i);
            temp[idx++] = s[i++];
            cnt = 0;
        }
    }

    while (i < m)temp[idx++] = s[i++];
    while (j <= r)temp[idx++] = s[j++];
    idx = 0;
    for (int p = l; p <= r; p++)s[p] = temp[idx++];
    return sum;
}
void mrg(int s[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mrg(s, l, mid);
        mrg(s, mid + 1, h);
        res += mrgS(s, l, mid + 1, h);
    }
}
signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];
    mrg(arr, 0, n - 1);
    cout << res << endl;
    return 0;
}
