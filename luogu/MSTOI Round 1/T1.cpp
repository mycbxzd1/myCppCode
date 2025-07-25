#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    getline(cin, x);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < x.length(); i++)
    {
        x[i] = tolower(x[i]);
        switch (x[i])
        {
        case 'm':
            cnt1++;
            break;
        case 's':
            cnt2++;
            break;
        case 't':
            cnt3++;
            break;
        default:
            break;
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3;
    return 0;
}