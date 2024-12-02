#include <bits/stdc++.h>
using namespace std;

const int N = 100003;
const int INF = 0x3f3f3f3f;

struct FastIO {
    void read(int &x) {
        x = 0;
        char c = getchar();
        while (c < '0' || c > '9') c = getchar();
        while (c >= '0' && c <= '9') {
            x = (x << 3) + (x << 1) + (c ^ 48);
            c = getchar();
        }
    }
    void print(int x) {
        if (x > 9) print(x / 10);
        putchar(x % 10 + '0');
    }
    void newline() {
        putchar('\n');
    }
} io;

struct FenwickTree {
    long long c1[N], c2[N];
    int n, p;
    FenwickTree(int _n, int _p) : n(_n), p(_p) {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int l, int r, int x) {
        x %= p;
        int ad1 = (long long)(l - 1) * x % p;
        int ad2 = (long long)r * x % p;
        for (int t = l; t <= n; t += lowbit(t)) {
            c1[t] = (c1[t] + x) % p;
            c2[t] = (c2[t] + ad1) % p;
        }
        for (int t = r + 1; t <= n; t += lowbit(t)) {
            c1[t] = (c1[t] - x + p) % p;
            c2[t] = (c2[t] - ad2 + p) % p;
        }
    }
    int prefixQuery(int i) {
        int res = 0;
        for (int t = i; t > 0; t -= lowbit(t)) {
            res = (res + (long long)i * c1[t] % p) % p;
            res = (res - c2[t] + p) % p;
        }
        return res;
    }
    int query(int l, int r) {
        return (prefixQuery(r) - prefixQuery(l - 1) + p) % p;
    }
};

struct Graph {
    vector<int> adj[N];
    int n;
    Graph(int _n) : n(_n) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const vector<int>& getAdj(int u) const {
        return adj[u];
    }
};

struct Tree {
    Graph& graph;
    FenwickTree& fenwickTree;
    int n, r, p, cnt;
    int son[N], depth[N], fa[N], size[N], id[N], top[N], w[N];
    Tree(Graph& _graph, FenwickTree& _fenwickTree, int _n, int _r, int _p) 
        : graph(_graph), fenwickTree(_fenwickTree), n(_n), r(_r), p(_p), cnt(0) {}
    void setWeight(int u, int weight) {
        w[u] = weight;
    }
    void dfs1(int u, int f) {
        fa[u] = f;
        size[u] = 1;
        depth[u] = depth[f] + 1;
        int t = -1;
        for (int v : graph.getAdj(u)) {
            if (v == f) continue;
            dfs1(v, u);
            size[u] += size[v];
            if (size[v] > t) {
                t = size[v];
                son[u] = v;
            }
        }
    }
    void dfs2(int u, int f) {
        top[u] = f;
        id[u] = ++cnt;
        if (w[u] != 0)
            fenwickTree.add(id[u], id[u], w[u]);
        if (son[u] == 0) return;
        dfs2(son[u], f);
        for (int v : graph.getAdj(u)) {
            if (v == son[u] || v == fa[u]) continue;
            dfs2(v, v);
        }
    }
    void init() {
        dfs1(r, 0);
        dfs2(r, r);
    }
    void addPath(int u, int v, int k) {
        k %= p;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            fenwickTree.add(id[top[u]], id[u], k);
            u = fa[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        fenwickTree.add(id[u], id[v], k);
    }
    int queryPath(int u, int v) {
        int res = 0;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            res = (res + fenwickTree.query(id[top[u]], id[u])) % p;
            u = fa[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res = (res + fenwickTree.query(id[u], id[v])) % p;
        return res;
    }
    void addSubtree(int u, int k) {
        k %= p;
        fenwickTree.add(id[u], id[u] + size[u] - 1, k);
    }
    int querySubtree(int u) {
        return fenwickTree.query(id[u], id[u] + size[u] - 1);
    }
};

int main() {
    int n, m, r, p;
    io.read(n), io.read(m), io.read(r), io.read(p);
    Graph graph(n);
    FenwickTree fenwickTree(n, p);
    Tree tree(graph, fenwickTree, n, r, p);
    for (int i = 1; i <= n; ++i) {
        int w;
        io.read(w);
        tree.setWeight(i, w);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        io.read(u), io.read(v);
        graph.addEdge(u, v);
    }
    tree.init();
    while (m--) {
        int op, x, y, z;
        io.read(op), io.read(x);
        if (op == 1) io.read(y), io.read(z), tree.addPath(x, y, z);
        else if (op == 2) io.read(y), io.print(tree.queryPath(x, y)), io.newline();
        else if (op == 3) io.read(z), tree.addSubtree(x, z);
        else io.print(tree.querySubtree(x)), io.newline();
    }
    return 0;
}
