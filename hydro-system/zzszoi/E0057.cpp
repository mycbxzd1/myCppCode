#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        vector<int> operator;
        int cnt = 0;
        bool possible = true;
        while (n != 1)
        {
            if (cnt > 40)
            {
                possible = false;
                break;
            }
            int k = (n - 1) / 2;
            if (n == 3)
                operator.push_back(2), n = (n - 1) / 2; // (3-1)/2 = 1
            else
            {
                if (k % 2 == 0)
                    operator.push_back(1), n = (n + 1) / 2;
                else
                    operator.push_back(2), n = (n - 1) / 2;
            }
            cnt++;
        }
        if (!possible || cnt > 40)
            cout << -1 << "\n";
        else
        {
            reverse(operator.begin(), operator.end());
            cout << operator.size() << "\n";
            for (size_t i = 0; i < operator.size(); i++)
                cout << operator[i] <<(i + 1 == operator.size() ? "\n" : " ");
        }
    }
    return 0;
}
