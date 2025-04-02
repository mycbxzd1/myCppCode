#include <bits/stdc++.h>
using namespace std;

class SplaySegmentTree {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        cin >> n >> m;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        
        // 分段树的节点数组大小开足够空间
        L.resize(4 * n + 10);
        R.resize(4 * n + 10);
        T.resize(4 * n + 10, 0);
        
        // splay 树节点数组（固定容量）
        tr.resize(MAX_NODE);
        idx = 0;
        
        build(1, 1, n);
        
        while (m--) {
            int op, a, b, x;
            cin >> op;
            if (op == 1) {
                cin >> a >> b >> x;
                cout << query(1, a, b, x) + 1 << "\n";
            } else if (op == 2) {
                cin >> a >> b >> x;
                int l = 0, r = 100000000;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (query(1, a, b, mid) + 1 <= x)
                        l = mid;
                    else
                        r = mid - 1;
                }
                cout << r << "\n";
            } else if (op == 3) {
                cin >> a >> x;
                change(1, a, x);
                w[a] = x;
            } else if (op == 4) {
                cin >> a >> b >> x;
                cout << query_pre(1, a, b, x) << "\n";
            } else {
                cin >> a >> b >> x;
                cout << query_suc(1, a, b, x) << "\n";
            }
        }
    }

private:
    struct Node {
        int s[2] = {0, 0}; // 子节点，0 表示空节点
        int p = 0;         // 父节点
        int v = 0;         // 节点的值
        int size = 0;      // 子树大小

        void init(int _v, int _p) {
            v = _v;
            p = _p;
            size = 1;
            s[0] = s[1] = 0;
        }
    };

    static constexpr int MAX_NODE = 2000010;
    static constexpr int INF = 1000000000;

    int n = 0, m = 0;
    int idx = 0;  // 当前 splay 树节点编号

    vector<Node> tr;      // splay树节点数组，从 1 开始，0 表示空
    vector<int> L, R;     // 分段树中每个节点对应的区间 [L[u], R[u]]
    vector<int> T;        // 分段树每个节点对应的 splay树根节点的索引
    vector<int> w;        // 原数组，下标从 1 开始

    // 更新节点 x 的子树大小
    void pushup(int x) {
        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
    }

    // 旋转操作
    void rotate(int x) {
        int y = tr[x].p, z = tr[y].p;
        int k = (tr[y].s[1] == x);
        if (z)
            tr[z].s[(tr[z].s[1] == y)] = x;
        tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1];
        if (tr[x].s[k ^ 1])
            tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y;
        tr[y].p = x;
        pushup(y);
        pushup(x);
    }

    // 将节点 x splay 到祖先 k 的下边
    void splay(int &root, int x, int k) {
        while (tr[x].p != k) {
            int y = tr[x].p, z = tr[y].p;
            if (z != k) {
                if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
                    rotate(x);
                else
                    rotate(y);
            }
            rotate(x);
        }
        if (k == 0)
            root = x;
    }

    // 向 splay 树中插入值 v
    void insert(int &root, int v) {
        int u = root, p = 0;
        while (u) {
            p = u;
            u = tr[u].s[v > tr[u].v];
        }
        u = ++idx;
        if (p)
            tr[p].s[v > tr[p].v] = u;
        tr[u].init(v, p);
        splay(root, u, 0);
    }

    // 返回 splay 树中小于 v 的节点个数
    int get_k(int root, int v) {
        int u = root, res = 0;
        while (u) {
            if (tr[u].v < v) {
                res += tr[tr[u].s[0]].size + 1;
                u = tr[u].s[1];
            } else {
                u = tr[u].s[0];
            }
        }
        return res;
    }

    // 在 splay 树中将值 x 更新为 y
    void update(int &root, int x, int y) {
        int u = root;
        while (u) {
            if (tr[u].v == x)
                break;
            if (tr[u].v < x)
                u = tr[u].s[1];
            else
                u = tr[u].s[0];
        }
        splay(root, u, 0);
        int l = tr[u].s[0], r = tr[u].s[1];
        while (tr[l].s[1])
            l = tr[l].s[1];
        while (tr[r].s[0])
            r = tr[r].s[0];
        splay(root, l, 0);
        splay(root, r, l);
        tr[r].s[0] = 0;
        pushup(r);
        pushup(l);
        insert(root, y);
    }

    // 构造分段树，每个节点维护一个 splay 树（存储该区间所有元素）
    void build(int u, int l, int r) {
        L[u] = l;
        R[u] = r;
        T[u] = 0;  // 初始化为空树
        insert(T[u], -INF);
        insert(T[u], INF);
        for (int i = l; i <= r; i++)
            insert(T[u], w[i]);
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    // 查询区间 [a, b] 中小于 x 的节点个数
    int query(int u, int a, int b, int x) {
        if (L[u] >= a && R[u] <= b)
            return get_k(T[u], x) - 1;
        int mid = (L[u] + R[u]) >> 1;
        int res = 0;
        if (a <= mid)
            res += query(u << 1, a, b, x);
        if (b > mid)
            res += query(u << 1 | 1, a, b, x);
        return res;
    }

    // 在分段树中更新下标 p 的值为 x
    void change(int u, int p, int x) {
        update(T[u], w[p], x);
        if (L[u] == R[u])
            return;
        int mid = (L[u] + R[u]) >> 1;
        if (p <= mid)
            change(u << 1, p, x);
        else
            change(u << 1 | 1, p, x);
    }

    // 在 splay 树中找小于 v 的最大值（前驱）
    int get_pre(int root, int v) {
        int u = root, res = -INF;
        while (u) {
            if (tr[u].v < v) {
                res = max(res, tr[u].v);
                u = tr[u].s[1];
            } else {
                u = tr[u].s[0];
            }
        }
        return res;
    }

    // 在 splay 树中找大于 v 的最小值（后继）
    int get_suc(int root, int v) {
        int u = root, res = INF;
        while (u) {
            if (tr[u].v > v) {
                res = min(res, tr[u].v);
                u = tr[u].s[0];
            } else {
                u = tr[u].s[1];
            }
        }
        return res;
    }

    // 查询区间 [a, b] 中小于 x 的最大值（前驱）
    int query_pre(int u, int a, int b, int x) {
        if (L[u] >= a && R[u] <= b)
            return get_pre(T[u], x);
        int mid = (L[u] + R[u]) >> 1;
        int res = -INF;
        if (a <= mid)
            res = max(res, query_pre(u << 1, a, b, x));
        if (b > mid)
            res = max(res, query_pre(u << 1 | 1, a, b, x));
        return res;
    }

    // 查询区间 [a, b] 中大于 x 的最小值（后继）
    int query_suc(int u, int a, int b, int x) {
        if (L[u] >= a && R[u] <= b)
            return get_suc(T[u], x);
        int mid = (L[u] + R[u]) >> 1;
        int res = INF;
        if (a <= mid)
            res = min(res, query_suc(u << 1, a, b, x));
        if (b > mid)
            res = min(res, query_suc(u << 1 | 1, a, b, x));
        return res;
    }
};

int main() {
    SplaySegmentTree sst;
    sst.solve();
    return 0;
}
