#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
    struct Node {
        int l, r;
        long long sum, add;
    };
    vector<Node> tree;
    SegmentTree(int n) {
        tree.resize(n * 4);
    }
    void build(int idx, int l, int r, const vector<long long>& arr) {
        tree[idx] = {l, r, 0, 0};
        if(l == r) {
            tree[idx].sum = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(idx * 2, l, mid, arr);
        build(idx * 2 + 1, mid + 1, r, arr);
        pushUp(idx);
    }
    void pushUp(int idx) {
        tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
    }
    void pushDown(int idx) {
        if(tree[idx].add) {
            int left = idx * 2, right = idx * 2 + 1;
            tree[left].add += tree[idx].add;
            tree[right].add += tree[idx].add;
            int mid = (tree[idx].l + tree[idx].r) >> 1;
            tree[left].sum += (long long)tree[left].add * (tree[left].r - tree[left].l + 1);
            tree[right].sum += (long long)tree[right].add * (tree[right].r - tree[right].l + 1);
            tree[left].sum += tree[idx].add * (mid - tree[idx].l + 1);
            tree[right].sum += tree[idx].add * (tree[idx].r - mid);
            tree[left].add += tree[idx].add;
            tree[right].add += tree[idx].add;
            tree[idx].add = 0;
        }
    }
    void update(int idx, int L, int R, int k) {
        if(L <= tree[idx].l && tree[idx].r <= R) {
            tree[idx].add += k;
            tree[idx].sum += (long long)k * (tree[idx].r - tree[idx].l + 1);
            return;
        }
        int mid = (tree[idx].l + tree[idx].r) >> 1;
        if(L <= mid) update(idx*2, L, R, k);
        if(R > mid) update(idx*2+1, L, R, k);
        pushUp(idx);
    }
    long long query(int idx, int L, int R) {
        if(L <= tree[idx].l && tree[idx].r <= R) {
            return tree[idx].sum;
        }
        int mid = (tree[idx].l + tree[idx].r) >> 1;
        long long res = 0;
        if(L <= mid) res += query(idx*2, L, R);
        if(R > mid) res += query(idx*2+1, L, R);
        return res;
    }
};

class HLD {
public:
    int n, timer;
    vector<int> weight;
    vector<vector<int>> adj;    
    vector<int> dep, fa, sz, son, top, id;
    vector<long long> newWeight;
    HLD(int n): n(n), timer(0) {
        weight.resize(n + 1);
        adj.resize(n + 1);
        dep.resize(n + 1);
        fa.resize(n + 1);
        sz.resize(n + 1);
        son.resize(n + 1, 0);
        top.resize(n + 1);
        id.resize(n + 1);
        newWeight.resize(n + 1);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs1(int u, int father, int depth) {
        dep[u] = depth;
        fa[u] = father;
        sz[u] = 1;
        for (int v : adj[u]) {
            if(v == father) continue;
            dfs1(v, u, depth + 1);
            sz[u] += sz[v];
            if(sz[v] > sz[son[u]]) {
                son[u] = v;
            }
        }
    }
    void dfs2(int u, int tp) {
        top[u] = tp;
        id[u] = ++timer;
        newWeight[timer] = weight[u];
        if(son[u] != 0) {
            dfs2(son[u], tp);
        }
        for (int v : adj[u]) {
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }
    void updatePath(int u, int v, int k, SegmentTree &seg) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]])
                swap(u, v);
            seg.update(1, id[top[u]], id[u], k);
            u = fa[top[u]];
        }
        if(dep[u] < dep[v]) swap(u, v);
        seg.update(1, id[v], id[u], k);
    }
    long long queryPath(int u, int v, SegmentTree &seg) {
        long long res = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]])
                swap(u, v);
            res += seg.query(1, id[top[u]], id[u]);
            u = fa[top[u]];
        }
        if(dep[u] < dep[v]) swap(u, v);
        res += seg.query(1, id[v], id[u]);
        return res;
    }
    void updateSubtree(int u, int k, SegmentTree &seg) {
        seg.update(1, id[u], id[u] + sz[u] - 1, k);
    }
    long long querySubtree(int u, SegmentTree &seg) {
        return seg.query(1, id[u], id[u] + sz[u] - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    HLD hld(n);
    for (int i = 1; i <= n; i++)
        cin >> hld.weight[i];
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        hld.addEdge(u, v);
    }
    hld.dfs1(1, 0, 1);
    hld.dfs2(1, 1);
    SegmentTree seg(n);
    seg.build(1, 1, n, hld.newWeight);
    int m;cin >> m;
    while(m--){
        int op;
        cin >> op;
        if(op == 1) {
            int u, v, k;
            cin >> u >> v >> k;
            hld.updatePath(u, v, k, seg);
        } else if(op == 2) {
            int u, k;
            cin >> u >> k;
            hld.updateSubtree(u, k, seg);
        } else if(op == 3) {
            int u, v;
            cin >> u >> v;
            cout << hld.queryPath(u, v, seg) << "\n";
        } else if(op == 4) {
            int u;
            cin >> u;
            cout << hld.querySubtree(u, seg) << "\n";
        }
    }
    return 0;
}
