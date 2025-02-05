#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
unsigned long long a[N];
int n, m, t, T;
int main()
{
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool zero = 0;
        t = n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i])
                    swap(a[i], a[j]);
            if (a[i] == 0){
                zero = 1, t = i - 1;
                break;
            }
            for (int k = 63; k >= 0; k--)
                if (a[i] >> k & 1)
                {
                    for (int j = 1; j <= n; j++)
                        if (i != j && (a[j] >> k & 1))
                            a[j] ^= a[i];
                    break;
                }
        }
        cin >> m;
        cout << "Case #" << C << ":" << endl;
        while (m--)
        {
            unsigned long long k, ans = 0;
            cin >> k;
            if (zero)
                k--;
            if (k >= 1llu << t)
                cout << "-1" << endl;
            else
            {
                for (int i = t - 1; i >= 0; i--)
                    if (k >> i & 1)
                        ans ^= a[t - i];
                cout << ans << endl;
            }
        }
    }
}