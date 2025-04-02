#include <bits/stdc++.h>
using namespace std;
const int N = 10008;
int f[108], sg[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, m, l, num;
    while (cin >> k, k)
    {
        for (int i = 1; i <= k; i++)
            cin >> f[i];
        memset(sg, 0, sizeof(sg));
        for (int i = 1; i < N; i++)
        {
            bool used[N] = {0};
            for (int j = 1; j <= k; j++)
            {
                if (i >= f[j])
                    used[sg[i - f[j]]] = true;
            }
            int g = 0;
            while (used[g])
                g++;
            sg[i] = g;
        }

        cin >> m;
        string ans;
        while (m--)
        {
            cin >> l;
            int sum = 0;
            while (l--)
            {
                cin >> num;
                sum ^= sg[num];
            }
            ans.push_back(sum ? 'W' : 'L');
        }
        cout << ans << '\n';
    }
    return 0;
}
