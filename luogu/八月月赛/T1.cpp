#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        string s1, s2;
        cin >> n >> m >> s1 >> s2;
        if (n > m)
        {
            cout << "No\n";
            continue;
        }
        int l = 0;
        while (l < n && l < m && s1[l] == s2[l])
            ++l;
        int r = 0;
        while (r < n - l && r < m - l && s1[n - 1 - r] == s2[m - 1 - r])
            ++r;
        cout << (l + r == n ? "Yes\n" : "No\n");
    }
    return 0;
}
