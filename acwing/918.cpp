#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int l, r, flag, sum;
};
class HLD
{
public:
    int n, m, p, x;
    vector<int> h, e, ne, id, dep, sz, top, fa, son;
    vector<Tree> tr;
    int idx, cnt;

    HLD(int n) : n(n), h(n + 1, -1), id(n + 1), dep(n + 1), sz(n + 1), top(n + 1),
                 fa(n + 1), son(n + 1), e(n), ne(n), tr(4 * n), idx(0), cnt(0) {}

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs1(int u, int depth)
    {
        dep[u] = depth, sz[u] = 1;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            dfs1(j, depth + 1);
            sz[u] += sz[j];
            if (sz[son[u]] < sz[j])
                son[u] = j;
        }
    }

    void dfs2(int u, int t)
    {
        id[u] = ++cnt, top[u] = t;
        if (!son[u])
            return;
        dfs2(son[u], t);
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != son[u])
                dfs2(j, j);
        }
    }

    void pushdown(int u)
    {
        auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        if (root.flag != -1)
        {
            left.sum = root.flag * (left.r - left.l + 1);
            right.sum = root.flag * (right.r - right.l + 1);
            left.flag = right.flag = root.flag;
            root.flag = -1;
        }
    }

    void pushup(int u)
    {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void build(int u, int l, int r)
    {
        tr[u] = {l, r, -1, 0};
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void update(int u, int l, int r, int k)
    {
        if (l <= tr[u].l && r >= tr[u].r)
        {
            tr[u].flag = k;
            tr[u].sum = k * (tr[u].r - tr[u].l + 1);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid)
            update(u << 1, l, r, k);
        if (r > mid)
            update(u << 1 | 1, l, r, k);
        pushup(u);
    }

    void update_path(int u, int v, int k)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            update(1, id[top[u]], id[u], k);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v])
            swap(u, v);
        update(1, id[v], id[u], k);
    }

    void update_tree(int u, int k)
    {
        update(1, id[u], id[u] + sz[u] - 1, k);
    }

    void solve()
    {
        cin >> m;
        while (m--)
        {
            string op;
            cin >> op >> x;
            x++;
            int tmp = tr[1].sum;
            if (op == "install")
            {
                update_path(1, x, 1);
                cout << tr[1].sum - tmp << endl;
            }
            else
            {
                update_tree(x, 0);
                cout << tmp - tr[1].sum << endl;
            }
        }
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    HLD hld(n);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        hld.add(++p, i);
        hld.fa[i] = p;
    }
    hld.dfs1(1, 1);
    hld.dfs2(1, 1);
    hld.build(1, 1, n);
    hld.solve();
    return 0;
}
