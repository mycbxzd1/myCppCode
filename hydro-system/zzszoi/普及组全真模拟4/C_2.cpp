#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 50010, mod = 1e9 + 7;
int f[N]; // �������ڴ洢��С���Ĵ�����
string s; //�ַ���
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
    for (int i = 0; i <= n; i++)f[i] = i;//ÿ���ַ�����һ�������Ļ��Ĵ�
    for (int i = 1; i <= n; i++) {
        f[i] = min(f[i], f[i - 1] + 1);
        for (int j = 1; j < i; j++) if (cha(i, j)) f[i] = min(f[i], f[j - 1] + 1);  // ��� s[j...i] ��һ�����Ĵ�
    }
    cout << f[n];
}

