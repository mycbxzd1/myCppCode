#include <iostream>
#include <string>
using namespace std;
int ans;
bool isfulltree(const string &s) {
    int need = 1;
    for (char c : s) {
        if (c == 'b') {
            need--;
        } else if (c == 'a') {
            need--;
            need += 2;
        }
        if (need < 0) return false; 
    }
    return need == 0;
}
int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int len = 1; len <= n; ++len) {
        int cur_ans = 0;
        for (int i = 0; i + len <= n; ++i) {
            string tmp = s.substr(i, len);
            if (isfulltree(tmp)) cur_ans++;
        }
        ans += cur_ans;
    }
    cout << ans << endl;
}
