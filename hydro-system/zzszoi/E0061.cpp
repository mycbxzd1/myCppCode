#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<long long> &a) : n(a.size() - 1)
    {
        tree.resize(n * 4);
        maxVal.resize(n * 4);
        build(1, 1, n, a);
    }
    long long query(int L, int R)
    {
        return query(1, 1, n, L, R);
    }
    void modifyMod(int L, int R, long long p)
    {
        modifyMod(1, 1, n, L, R, p);
    }
    void modify(int pos, long long val)
    {
        modify(1, 1, n, pos, val);
    }

private:
    int n;
    vector<long long> tree, maxVal;
    void pushUp(int rt)
    {
        tree[rt] = tree[rt * 2] + tree[rt * 2 + 1];
        maxVal[rt] = max(maxVal[rt * 2], maxVal[rt * 2 + 1]);
    }
    void build(int rt, int l, int r, const vector<long long> &a)
    {
        if (l == r)
        {
            tree[rt] = maxVal[rt] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(rt * 2, l, mid, a);
        build(rt * 2 + 1, mid + 1, r, a);
        pushUp(rt);
    }
    void modifyMod(int rt, int l, int r, int L, int R, long long p)
    {
        if (maxVal[rt] < p)
            return;
        if (l == r)
        {
            tree[rt] %= p;
            maxVal[rt] %= p;
            return;
        }
        int mid = (l + r) / 2;
        if (L <= mid)
            modifyMod(rt * 2, l, mid, L, R, p);
        if (R > mid)
            modifyMod(rt * 2 + 1, mid + 1, r, L, R, p);
        pushUp(rt);
    }
    void modify(int rt, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            tree[rt] = maxVal[rt] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            modify(rt * 2, l, mid, pos, val);
        else
            modify(rt * 2 + 1, mid + 1, r, pos, val);
        pushUp(rt);
    }
    long long query(int rt, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return tree[rt];
        int mid = (l + r) / 2;
        long long res = 0;
        if (L <= mid)
            res += query(rt * 2, l, mid, L, R);
        if (R > mid)
            res += query(rt * 2 + 1, mid + 1, r, L, R);
        return res;
    }
};

int main()
{
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree segTree(a);
    while (q--)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
            cout << segTree.query(x, y) << "\n";
        else if (opt == 2)
        {
            long long p;
            cin >> p;
            segTree.modifyMod(x, y, p);
        }
        else if (opt == 3)
            segTree.modify(x, y);
    }
    return 0;
}
