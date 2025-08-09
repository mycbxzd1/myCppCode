#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, expected, output;
    if (!getline(cin, S)) return 0;
    getline(cin, expected);
    getline(cin, output);

    int n = S.size();
    int start = -1;
    set<int> init;
    for (int i = 0; i < n; i++) {
        if (S[i] == 'X') start = i;
        else if (S[i] == '#') init.insert(i);
    }

    auto simulate = [&](const string &ops) {
        int pos = start;
        set<int> mons = init;
        char last = '\0';
        if ((int)ops.size() > 3 * n) return false;
        for (char c : ops) {
            if (c!='L' && c!='R' && c!='D') return false;
            if (c == last) return false;
            last = c;
            if (c == 'D') {
                // 向右移动
                if (mons.count(pos + 1)) return false;
                pos++;
            } else if (c == 'L') {
                auto it = mons.lower_bound(pos);
                if (it != mons.begin()) {
                    --it;
                    mons.erase(it);
                }
            } else { // 'R'
                auto it = mons.upper_bound(pos);
                if (it != mons.end()) {
                    mons.erase(it);
                }
            }
            // 怪物移动
            set<int> next;
            for (int m : mons) {
                if (m == pos) return false;
                if (m < pos) next.insert(m + 1);
                else next.insert(m - 1);
            }
            mons.swap(next);
        }
        return mons.empty();
    };

    bool ok;
    if (expected.empty()) {
        ok = output.empty();
    } else {
        ok = simulate(output);
    }
    cout << (ok ? "AC" : "WA");
    return 0;
}
