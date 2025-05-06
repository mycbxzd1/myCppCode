#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int n = S.size();
        /* 全部相同则原封不动 */
        if (all_of(S.begin(), S.end(), [](char c)
                   { return c == '0'; }) ||
            all_of(S.begin(), S.end(), [](char c)
                   { return c == '1'; }))
        {

            cout << S << "\n";
            continue;
        }
        /* 首尾不同则一个不留 */
        char c0 = S[0], c1 = S[n - 1];
        if (c0 != c1)
        {
            cout << "\n";
            continue;
        }
        /* 连续两相同则一个不留 */
        char d = (c0 == '0' ? '1' : '0');
        bool canEmpty = false;
        for (int i = 0; i + 1 < n; i++)
        {
            if (S[i] == d && S[i + 1] == d)
            {
                canEmpty = true;
                break;
            }
        }
        if (canEmpty)
        {
            cout << "\n";
            continue;
        }
        /* 其余则统计法求最优 */
        int total0 = 0, total1 = 0;
        int runs0 = 0, runs1 = 0;
        int minRun0 = n + 1, minRun1 = n + 1;
        for (char c : S)
        {
            if (c == '0')
                total0++;
            else
                total1++;
        }
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && S[j] == S[i])
                j++;
            int len = j - i;
            if (S[i] == '0')
                runs0++, minRun0 = min(minRun0, len);
            else
                runs1++, minRun1 = min(minRun1, len);
            i = j;
        }
        if (total0 > runs1)
            cout << string(minRun0, '0') << "\n";
        else
            cout << string(minRun1, '1') << "\n";
    }
    return 0;
}
