#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> edges;
    int n;
    if (b == 0)
    {
        if (a == 0)
        {
            cout << 1;
            return 0;
        }
        if (a == 2)
        {
            cout << "2\n1 2";
            return 0;
        }
        if (a >= 4)
        {
            n = a + 1;
            cout << n << "\n";
            for (int i = 2; i <= a + 1; i++)
                cout << 1 << " " << i << "\n";
            return 0;
        }
        cout << 0;
        return 0;
    }
    int delta = a - (b + 2);
    if (delta < 0 || delta == 1)
    {
        cout << 0;
        return 0;
    }
    n = b;
    for (int i = 1; i < b; i++)
        edges.emplace_back(i, i + 1);
    vector<int> freeDeg(5005, 0);
    for (int i = 1; i <= b; i++)
        freeDeg[i] = 3;
    if (b > 1)
    {
        for (int i = 1; i <= b; i++)
        {
            if (i == 1 || i == b)
                freeDeg[i]--;
            else
                freeDeg[i] -= 2;
        }
    }
    if (delta > 0)
    {
        n++;
        int D = n;
        edges.emplace_back(1, D);
        freeDeg[1]--;
        freeDeg[D] = delta + 1;
    }
    for (int i = 0; i < a; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (freeDeg[u] > 0)
            {
                n++;
                edges.emplace_back(u, n);
                freeDeg[u]--;
                break;
            }
        }
    }
    cout << n << "\n";
    for (auto &e : edges)
        cout << e.first << " " << e.second << "\n";
    return 0;
}
