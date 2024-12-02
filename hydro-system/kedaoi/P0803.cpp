#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1005;
int n;
string s[N];
int v[N], ans;

int pd(const string& a, const string& b) {
    int l = 1;
    while (l < a.size() && l < b.size()) {
        string a_lst = a.substr(a.size() - l, l);
        string b_fst = b.substr(0, l);
        if (a_lst == b_fst) return l;
        ++l;
    }
    return 0;
}

void dfs(int i, int len) {  // s[3] - s[2] - s[i]
    ans = max(ans, len);

    for (int j = 1; j <= n; j++) {
        if (v[j] == 2) continue;
        int l = pd(s[i], s[j]);
        if (l) {
            v[j]++;
            dfs(j, len + s[j].size() - l);
            v[j]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    char ch;
    cin >> ch;
    for (int i = 1; i <= n; i++) {
        if (s[i][0] == ch) {
            ++v[i];
            dfs(i, s[i].size());  // 接龙末尾单词是s[i]
            --v[i];
        }
    }

    cout << ans << endl;
    return 0;
}
