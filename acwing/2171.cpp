#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
struct Edge
{
    int x, y, a, b;
    bool operator<(const Edge &t) const
    {
        return a < t.a;
    }
};
struct Node
{
    int s[2], p, v, mx, rev;
};
class LinkCutTree
{
public:
    vector<Node> tr;
    vector<int> stk;
    int size;
    LinkCutTree(int n) : size(n)
    {
        tr.resize(n + 1);
        stk.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            tr[i].s[0] = tr[i].s[1] = tr[i].p = tr[i].v = tr[i].mx = tr[i].rev = 0;
        }
    }
    void pushrev(int x)
    {
        swap(tr[x].s[0], tr[x].s[1]);
        tr[x].rev ^= 1;
    }
    void pushup(int x)
    {
        tr[x].mx = x;
        for (int i = 0; i < 2; i++)
            if (tr[tr[x].s[i]].v > tr[tr[x].mx].v)
                tr[x].mx = tr[x].s[i];
    }
    void pushdown(int x)
    {
        if (tr[x].rev)
        {
            if (tr[x].s[0])
                pushrev(tr[x].s[0]);
            if (tr[x].s[1])
                pushrev(tr[x].s[1]);
            tr[x].rev = 0;
        }
    }
    bool isroot(int x)
    {
        int p = tr[x].p;
        return (tr[p].s[0] != x && tr[p].s[1] != x);
    }
    void rotate(int x)
    {
        int y = tr[x].p, z = tr[y].p;
        int k = (tr[y].s[1] == x);
        if (!isroot(y))
            tr[z].s[tr[z].s[1] == y] = x;
        tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1];
        if (tr[x].s[k ^ 1])
            tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y;
        tr[y].p = x;
        pushup(y);
        pushup(x);
    }
    void splay(int x)
    {
        int top = 0;
        stk[++top] = x;
        for (int i = x; !isroot(i); i = tr[i].p)
            stk[++top] = tr[i].p;
        while (top)
            pushdown(stk[top--]);
        while (!isroot(x))
        {
            int y = tr[x].p, z = tr[y].p;
            if (!isroot(y))
                if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
                    rotate(x);
                else
                    rotate(y);
            rotate(x);
        }
    }
    void access(int x)
    {
        int y = 0;
        while (x)
        {
            splay(x);
            tr[x].s[1] = y;
            pushup(x);
            y = x;
            x = tr[x].p;
        }
    }
    void makeroot(int x)
    {
        access(x);
        splay(x);
        pushrev(x);
    }
    int findroot(int x)
    {
        access(x);
        splay(x);
        while (tr[x].s[0])
        {
            pushdown(x);
            x = tr[x].s[0];
        }
        splay(x);
        return x;
    }
    void split(int x, int y)
    {
        makeroot(x);
        access(y);
        splay(y);
    }
    void link(int x, int y)
    {
        makeroot(x);
        if (findroot(y) != x)
            tr[x].p = y;
    }
    void cut(int x, int y)
    {
        makeroot(x);
        if (findroot(y) == x && tr[y].p == x && tr[y].s[0] == 0)
        {
            tr[x].s[1] = 0;
            tr[y].p = 0;
            pushup(x);
        }
    }
};
class DSU
{
public:
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x != y)
            parent[x] = y;
    }
};
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> edges[i].x >> edges[i].y >> edges[i].a >> edges[i].b;
    sort(edges.begin() + 1, edges.end());
    int total = n + m;
    DSU dsu(total);
    LinkCutTree lct(total);
    for (int i = n + 1; i <= total; i++)
    {
        lct.tr[i].v = edges[i - n].b;
        lct.tr[i].mx = i;
    }
    int res = INF;
    for (int i = 1; i <= m; i++)
    {
        int x = edges[i].x, y = edges[i].y, a = edges[i].a, b = edges[i].b;
        if (dsu.find(x) == dsu.find(y))
        {
            lct.split(x, y);
            int t = lct.tr[y].mx;
            if (lct.tr[t].v > b)
            {
                lct.cut(edges[t - n].x, t);
                lct.cut(t, edges[t - n].y);
                lct.link(x, n + i);
                lct.link(n + i, y);
            }
        }
        else
        {
            dsu.unite(x, y);
            lct.link(x, n + i);
            lct.link(n + i, y);
        }
        if (dsu.find(1) == dsu.find(n))
        {
            lct.split(1, n);
            res = min(res, a + lct.tr[lct.tr[n].mx].v);
        }
    }
    cout << (res == INF ? -1 : res) << "\n";
    return 0;
}
