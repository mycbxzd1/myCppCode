#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int N = 5005;
bool dp[N][N];  // dp[i][j] 表示从 i 到 j 是否可以删除
bool is_palindrome[N][N]; // is_palindrome[i][j] 表示从 i 到 j 是否是回文
string s;

bool check_palindrome(int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    cin >> s;
    int n = s.size();

    // 初始化is_palindrome
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            is_palindrome[i][j] = check_palindrome(i, j);
        }
    }

    // 初始化dp数组
    memset(dp, 0, sizeof(dp));

    // 长度为1的子串是回文且可以删除
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // 处理长度大于等于2的子串
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (is_palindrome[i][j]) {
                if (i == 0 && j == n - 1) dp[i][j] = true;  // 整个串是回文，可以删除
                else if (i == 0) dp[i][j] = dp[j + 1][n - 1];  // 处理前面删除
                else if (j == n - 1) dp[i][j] = dp[0][i - 1];  // 处理后面删除
                else dp[i][j] = dp[0][i - 1] && dp[j + 1][n - 1];  // 处理两边删除
            }
        }
    }

    // 判断整个字符串是否可以被删除
    if (dp[0][n - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

