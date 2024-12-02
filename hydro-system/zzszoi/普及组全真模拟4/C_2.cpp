#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 50010, mod = 1e9 + 7;
int f[N]; // 数组用于存储最小回文串划分
string s; //字符串
bool cha(int i, int j) {
    while (j <= i) {
        if (s[i] != s[j])return false;
        i--;j++;
    }
    return true;
}
signed main() {
    cin>>s;s=" "+s; 
    int n = s.length(); 
    for (int i = 0; i <= n; i++)f[i] = i;//每个字符都是一个单独的回文串
    for (int i = 1; i <= n; i++) {
        f[i] = min(f[i], f[i - 1] + 1);
        for (int j = 1; j < i; j++) if (cha(i, j)) f[i] = min(f[i], f[j - 1] + 1);  // 如果 s[j...i] 是一个回文串
    }
    cout << f[n];
}

