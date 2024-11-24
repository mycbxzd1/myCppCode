#include<bits/stdc++.h>
using namespace std;
int sum[int(1e5+7)];

int main() {
    string a;
    cin >> a;
    int n = a.length();
    int cnt = 0, mx = 0, mx1 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            cnt++;
        } else {
            mx = max(mx, cnt);
            cnt = 0;
        }
        sum[i] = cnt;
    }
    mx = max(mx, cnt);
    
    for (int i = 0; i < n; i++) {
        if (sum[i] == mx) {
            a[i - (sum[i] / 2)] = '0';
            break;
        }
    }

    cnt = 0, mx1 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            cnt++;
        } else {
            mx1 = max(mx1, cnt);
            cnt = 0;
        }
    }
    mx1 = max(mx1, cnt);

    cout << mx1 << endl;
}

