#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int zero = 0, one = 0;
        string x;
        cin >> x;
        for (int i = 0; i < x.length(); i++)
            (x[i] == '0' ? zero++ : one++);
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '0')
            {
                if (one)
                    one--;
                else
                    break;
            }
            else
            {
                if (zero)
                    zero--;
                else
                    break;
            }
        }

        cout << one + zero << endl;
    }
    return 0;
}