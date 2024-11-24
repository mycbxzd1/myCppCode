#include<bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    int n = a.length();
    vector<int> ones;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') cnt++;
        else {
            if (cnt > 0) ones.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0) ones.push_back(cnt);
    int maxCombat = 0, reducedCombat = 0;
    for (int len : ones) maxCombat = max(maxCombat, len);
    for (int len : ones) {
        if (len > 1) reducedCombat = max(reducedCombat, (len + 1) / 2);
    }
    cout << max(maxCombat - reducedCombat, 0) << endl;
    return 0;
}

