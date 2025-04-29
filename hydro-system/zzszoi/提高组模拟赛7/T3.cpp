#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 1000000 + 50;
struct Node
{
    int x, y;
};
Node t[MAXN];
bool cl[MAXN], ans[MAXN];
int n, m;
class DSU
{
public:
    DSU(int x)
    {
        init(x);
    }
    int find(int x) const
    {
        return (fa[x] == x ? x : find(fa[x]));
    }
    bool unite(int x, int y)
    {
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        uni[++cnt] = {x, y};
        fa[y] = x;
        siz[x] += siz[y];
        return true;
    }
    bool back(int x, int y)
    {
        int px = uni[cnt].first;
        int py = uni[cnt--].second;
        fa[py] = py;
        siz[px] -= siz[py];
        if ((siz[px] & 1) || (siz[py] & 1))
        {
            add(x);
            add(y);
            return true;
        }
        return false;
    }
    void add(int x)
    {
        while (x)
        {
            siz[x]++;
            if (x == fa[x])
                break;
            x = fa[x];
        }
    }

private:
    vector<pair<int, int>> uni;
    vector<int> fa, siz;
    int cnt;
    void init(int x)
    {
        fa.assign(x + 5, 0);
        siz.assign(x + 5, 0);
        uni.resize(x + 5);
        cnt = 0;
        for (int i = 1; i <= x; ++i)
        {
            fa[i] = i;
            siz[i] = 1;
        }
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        t[i].x = x + 1;
        t[i].y = y + 1;
    }
    DSU dsu(n);
    for (int i = m; i >= 1; --i)
        cl[i] = dsu.unite(dsu.find(t[i].x), dsu.find(t[i].y));
    for (int i = 1; i <= m; ++i)
    {
        if (cl[i])
            ans[i] = dsu.back(t[i].x, t[i].y);
        else
        {
            dsu.add(t[i].x);
            dsu.add(t[i].y);
            ans[i] = true;
        }
    }
    for (int i = 1; i <= m; ++i)
        cout << (ans[i] ? '1' : '0');
    cout << '\n';
    return 0;
}
