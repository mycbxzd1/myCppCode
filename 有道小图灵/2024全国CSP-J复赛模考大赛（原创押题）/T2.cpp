#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
deque<int> a; 
int d, x, k, now = 0;
int main() {
    cin >> d >> x;
    int cnt = -1;
    while (x != 0) {
        if (x == 1) {
            if (a.size() == d) a.pop_front();
            a.push_back(++now);
            cnt = a.size() - 1;
        }
        else if (x == 2) {
            cin >> k;
            if (a.empty()) {
                cout << "Error: no forward history" << endl;
            } else if (cnt + k >= a.size()) {
                cout << "Error: no forward history" << endl;
            } else {
                cnt += k;
                cout << a[cnt] << endl;
            }
        }
        else if (x == 3) {
            cin >> k;
            if (a.empty()) {
                cout << "Error: no back history" << endl;
            } else if (cnt - k < 0) {
                cout << "Error: no back history" << endl;
            } else {
                cnt -= k;
                cout << a[cnt] << endl;
            }
        }
        else if (x == 4) {
            a.clear();
            cnt = -1;
        }

        cin >> x;
    }
}
