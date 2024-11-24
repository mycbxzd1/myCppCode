#include <bits/stdc++.h>
using namespace std;
int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int pos;
    cin >> pos;
    return pos;
}
int main() {
    int n;cin >> n;
    if(n==3){
    	int ans13, ans12, ans23;
        cout << "? 1 3" << endl;
        cin >> ans13;
        cout << "? 1 2\n";
        cout.flush();
        cin >> ans12;
        cout << "? 2 3\n";
        fflush(stdout);
        cin >> ans23;
        if (ans13 == 1){
            if (ans23 == 2)cout << "! 3" << endl;
            else cout << "! 2" << endl;
        }
        if (ans13 == 2){
            if (ans12 == 1)cout << "! 3" << endl;
            else cout << "! 1" << endl;
        }
        if (ans13 == 3){
            if (ans12 == 1)cout << "! 2" << endl;
            else cout << "! 1" << endl;
        }
    }
    int l = 1, r = n;
    while (l < r) {
        int pos = query(l, r);
        if (pos == l) {
            int sec_pos = query(l + 1, r);
            if (sec_pos == l + 1) {
                l = sec_pos;
                break;
            }
        } else if (pos == r) {
            int sec_pos = query(l, r - 1);
            if (sec_pos == r - 1) {
                r = sec_pos;
                break;
            }
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) r = mid;
            else l = mid + 1;
        }
        
    }
    cout << "! " << l << endl;
    return 0;
}

