#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin >> s;
    char col[4] = {'!', '!', '!', '!'};
    int ans[4] = {0, 0, 0, 0};
    for (int i = 0; i < s.size(); i++)if (s[i] != '!') col[i % 4] = s[i];
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') {
            char color = col[i % 4];
            if (color == 'R') ans[0]++;
            else if (color == 'O') ans[1]++;
            else if (color == 'W') ans[2]++;
            else if (color == 'B') ans[3]++;
        }
    }

    for (int i = 0; i < 4; i++)cout << ans[i] << ' ';
    return 0;
}
