#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        string x;
        cin >> x;
        for (int i = 1; i < x.length(); i++)
        {
            if (x[0] == '0' || x[i] == '0')
                continue;
            string m = x.substr(0, i);
            string n = x.substr(i);
            int a = stoi(m), b = stoi(n);
            if (a > 0 && b > 0 && b > a)
            {
                cout << a << " " << b << endl;
                goto end;
            }
        }
        cout << -1 << endl;
    end:
        continue;
    }
    return 0;
}

