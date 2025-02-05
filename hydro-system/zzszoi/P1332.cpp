#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N], n, ans;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1, j; i <= n; i++)
        {
            cin >> j;
            a[i] ^= j;
            a[i] |= 1 << i;
        }
        int x, y;
        while (cin >> x >> y && x && y)
            a[y] |= 1 << x;
        ans = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i])
                    swap(a[i], a[j]);
            if (a[i] == 0)ans = 1 << (n - i + 1),break;
            if (a[i] == 1)ans = 0,break;
            for (int k = n; k; k--){
                if (a[i] >> k & 1)
                {
                    for (int j = 1; j <= n; j++)
                        if (i != j && (a[j] >> k & 1))
                            a[j] ^= a[i];
                    break;
                }
            } 
        }
        if (ans == 0)
            puts("Oh,it's impossible~!!");
        else
            cout << ans << endl;
    }
}