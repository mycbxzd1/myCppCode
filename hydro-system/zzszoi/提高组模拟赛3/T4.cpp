#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
    SegmentTree(int size, function<int(int)> compute)
        : n(size), computeLeaf(compute), tree(4 * size, 0) {}
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = computeLeaf(start);
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int node, int start, int end, int pos) {
        if (start == end) {
            tree[node] = computeLeaf(start);
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(2 * node, start, mid, pos);
        else
            update(2 * node + 1, mid + 1, end, pos);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int query(int node, int start, int end, int l, int r) const {
        if (r < start || l > end)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }

private:
    int n;
    vector<int> tree;
    function<int(int)> computeLeaf;
};

class Trade {
public:
    Trade(int n, int m) : n(n), m(m) {
        v.resize(n + 1);
    }
    void readPrices() {
        for (int i = 1; i <= n; ++i) 
            cin >> v[i];
    }

    void initSegmentTrees() {
        if (n > 1) {
            segTreeLT = new SegmentTree(n - 1, [this](int index) -> int {
                return (index < n) ? max(v[index + 1] - v[index], 0) : 0;
            });
            segTreeLT->build(1, 1, n - 1);
            segTreeRT = new SegmentTree(n - 1, [this](int index) -> int {
                return (index < n) ? max(v[index] - v[index + 1], 0) : 0;
            });
            segTreeRT->build(1, 1, n - 1);
        }
    }
    int query(int a, int b) const {
        if (a == b || n == 1)
            return 0;
        if (a < b)
            return segTreeLT->query(1, 1, n - 1, a, b - 1);
        else
            return segTreeRT->query(1, 1, n - 1, b, a - 1);
    }
    void update(int p, int val) {
        v[p] = val;
        if (n > 1) {
            if (p > 1) {
                segTreeRT->update(1, 1, n - 1, p - 1);
                segTreeLT->update(1, 1, n - 1, p - 1);
            }
            if (p < n) {
                segTreeRT->update(1, 1, n - 1, p);
                segTreeLT->update(1, 1, n - 1, p);
            }
        }
    }
    void processQueries() {
        int op;
        while (m--) {
            cin >> op;
            if (op == 1) {
                int a, b;
                cin >> a >> b;
                cout << query(a, b) << "\n";
            } else { // op == 2
                int p, val;
                cin >> p >> val;
                update(p, val);
            }
        }
    }
    ~Trade() {
        delete segTreeLT;
        delete segTreeRT;
    }

private:
    int n, m;
    vector<int> v;
    SegmentTree *segTreeLT = nullptr;
    SegmentTree *segTreeRT = nullptr;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("trade.in", "r", stdin);
    freopen("trade.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    Trade trade(n, m);
    trade.readPrices();
    trade.initSegmentTrees();
    trade.processQueries();

    return 0;
}
