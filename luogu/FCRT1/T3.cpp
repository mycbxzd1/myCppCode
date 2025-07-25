#include <bits/stdc++.h>
using namespace std;
#define int long long

inline char change(char c, int k)
{
    int id = (c <= 'Z' ? c - 'A' : c - 'a' + 26);
    id = (id + k + 52) % 52;
    return id < 26 ? char('A' + id) : char('a' + id - 26);
}

string buildQuery(int len, int kCnt)
{
    string res;
    for (int mx = 1; mx <= kCnt; ++mx)
    {
        int grp = kCnt / mx;
        long long used = (long long)mx * grp * (grp - 1) / 2 + (kCnt % mx) * grp;
        if (used > len)
            continue;
        for (int i = 0; i < kCnt; ++i)
        {
            int tms = i / mx;
            while (tms--)
                res.push_back(char(i));
        }
        res.append(len - used, char(kCnt - 1));
        break;
    }
    return res;
}

string t;
bool done;
void solveRange(int l, int r)
{
    if (done)
        return;
    string q = buildQuery(t.size(), r - l + 1);
    vector<int> cnt(r - l + 1);
    for (int i = 0; i < t.size(); ++i)
    {
        cnt[q[i]]++;
        q[i] = change(t[i], -(q[i] + l));
    }
    cout << q << '\n'
         << flush;
    int x;
    cin >> x;
    if (x == t.size())
    {
        done = 1;
        return;
    }
    int L = INT_MAX, R = -1;
    for (int i = 0; i < r - l + 1; ++i)
        if (cnt[i] == x)
        {
            L = min(L, i);
            R = max(R, i);
        }
    solveRange(L + l, R + l);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q))
        return 0;
    while (q--)
    {
        cin >> t;
        done = 0;
        if (t.size() == 1)
        {
            for (int i = 0; i < 52; ++i)
            {
                cout << change('a', i) << '\n'
                     << flush;
                int x;
                cin >> x;
                if (x == 1)
                    break;
            }
        }
        else
            solveRange(0, 51);
    }
    return 0;
}
