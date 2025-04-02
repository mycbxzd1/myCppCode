#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int q;
        cin >> q;
        int op, atk, regen, hp;
        int minTurn = -1, maxTurn = 1e18;
        auto check = [&](int &curL, int &curR, int newL, int newR, bool update)
        {
            int L = max(curL, newL), R = min(curR, newR);
            if (L > R)
                return false;
            if (update)
                curL = L, curR = R;
            return true;
        };
        while (q--)
        {
            cin >> op;
            if (op == 1)
            {
                cin >> atk >> regen >> hp;
                int L = -1, R = -1;
                if (hp == 1)
                    L = 1, R = atk;
                else
                {
                    int base = (atk - regen) * (hp - 2);
                    L = base + atk + 1;
                    R = base + atk + (atk - regen);
                }
                cout << check(minTurn, maxTurn, L, R, true) << ' ';
            }
            else
            {
                cin >> atk >> regen;
                int res = 0;
                if (atk >= minTurn)
                    res = 1;
                else
                {
                    int diff = atk - regen;
                    int needed = minTurn - atk;
                    res = (needed + diff - 1) / diff + 1;
                }
                hp = res + 1;
                int L = -1, R = -1;
                if (hp == 1)
                    L = 1, R = atk;
                else
                {
                    int base = (atk - regen) * (hp - 2);
                    L = base + atk + 1;
                    R = base + atk + (atk - regen);
                }
                if (check(minTurn, maxTurn, L, R, false))
                    res = -1;
                cout << res << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
