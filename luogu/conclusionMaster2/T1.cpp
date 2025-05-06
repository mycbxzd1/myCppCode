#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], L[N];
string S[N];
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    L[1] = a[1] + 1;
    for (int i = 2; i <= n; i++)
        L[i] = max(a[i - 1], a[i]) + 1;
    L[n + 1] = a[n] + 1;
    S[1].assign(L[1], 'a');
    for (int i = 1; i <= n; i++)
    {
        char flag = S[i][a[i]];
        char ch = (flag == 'a' ? 'b' : 'a');
        S[i + 1].assign(L[i + 1], ch);
        for (int j = 0; j < a[i]; j++)
            S[i + 1][L[i + 1] - a[i] + j] = S[i][j];
    }
    for (int i = 1; i <= n + 1; i++)
        cout << S[i] << "\n";
    return 0;
}
