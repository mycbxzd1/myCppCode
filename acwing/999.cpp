#include<bits/stdc++.h>
using namespace std;
const int N = 150010, INF = 1e8;
class UnionFind {
public:
    int p[N];
    UnionFind(int size) {
        for (int i = 1; i <= size; i++) p[i] = i;
    }
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void unite(int x, int y) {
        p[find(x)] = find(y);
    }
};
class LinkCutTree {
public:
    struct Node {
        int s[2], p, v;
        int mx, rev;
    } tr[N];
    int stk[N];
    LinkCutTree() {}
    void pushrev(int x) {
        swap(tr[x].s[0], tr[x].s[1]);
        tr[x].rev ^= 1;
    }
    void pushup(int x) {
        tr[x].mx = x;
        for (int i = 0; i < 2; i++)
            if (tr[tr[tr[x].s[i]].mx].v > tr[tr[x].mx].v)
                tr[x].mx = tr[tr[x].s[i]].mx;
    }
    void pushdown(int x) {
        if (tr[x].rev) {
            pushrev(tr[x].s[0]);
            pushrev(tr[x].s[1]);
            tr[x].rev = 0;
        }
    }
    bool isroot(int x) {
        return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
    }
    void rotate(int x) {
        int y = tr[x].p, z = tr[y].p;
        int k = (tr[y].s[1] == x);
        if (!isroot(y)) tr[z].s[tr[z].s[1] == y] = x;
        tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1];
        tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y;
        tr[y].p = x;
        pushup(y);
        pushup(x);
    }
    void splay(int x) {
        int top = 0, r = x;
        stk[++top] = x;
        while (!isroot(r)) {
            stk[++top] = r = tr[r].p;
        }
        while (top) pushdown(stk[top--]);
        while (!isroot(x)) {
            int y = tr[x].p, z = tr[y].p;
            if (!isroot(y))
                if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
                    rotate(x);
                else
                    rotate(y);
            rotate(x);
        }
    }
    void access(int x) {
        int y = 0, z = x;
        while (x) {
            splay(x);
            tr[x].s[1] = y;
            pushup(x);
            y = x;
            x = tr[x].p;
        }
        splay(z);
    }
    void makeroot(int x) {
        access(x);
        pushrev(x);
    }
    int findroot(int x) {
        access(x);
        while (tr[x].s[0]) {
            pushdown(x);
            x = tr[x].s[0];
        }
        splay(x);
        return x;
    }
    void split(int x, int y) {
        makeroot(x);
        access(y);
    }
    void link(int x, int y) {
        makeroot(x);
        if (findroot(y) != x) tr[x].p = y;
    }
    void cut(int x, int y) {
        makeroot(x);
        if (findroot(y) == x && tr[y].p == x && !tr[y].s[0]) {
            tr[x].s[1] = 0;
            tr[y].p = 0;
            pushup(x);
        }
    }
};
struct Edge {
    int x, t, a, b;
    bool operator< (const Edge &other) const {
        return a < other.a;
    }
} e[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        e[i] = {x, y, a, b};
    }
    sort(e + 1, e + m + 1);
    UnionFind uf(n + m);
    LinkCutTree lct;
    for (int i = 1; i <= n + m; i++) {
        uf.p[i] = i;
        lct.tr[i].s[0] = lct.tr[i].s[1] = 0;
        lct.tr[i].p = 0;
        lct.tr[i].rev = 0;
        if (i > n) lct.tr[i].v = e[i - n].b;
        lct.tr[i].mx = i;
    }
    int res = INF;
    for (int i = 1; i <= m; i++) {
        int x = e[i].x, y = e[i].t, a = e[i].a, b = e[i].b;
        if (uf.find(x) == uf.find(y)) {
            lct.split(x, y);
            int t = lct.tr[y].mx;
            if (lct.tr[t].v > b) {
                lct.cut(e[t - n].x, t);
                lct.cut(t, e[t - n].t);
                lct.link(x, n + i);
                lct.link(n + i, y);
            }
        } else {
            uf.unite(x, y);
            lct.link(x, n + i);
            lct.link(n + i, y);
        }
        if (uf.find(1) == uf.find(n)) {
            lct.split(1, n);
            res = min(res, a + lct.tr[lct.tr[n].mx].v);
        }
    }
    if (res == INF) res = -1;
    cout << res << "\n";
    return 0;
}
