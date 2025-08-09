#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 2e5 + 10;
const int RANGE_L = 1, RANGE_R = MAXN;
struct Point
{
    int val = 0;
    Point* left = nullptr;
    Point* right = nullptr;
};
class SegmentTree
{
private:
    const int L = 1, R = 1e9;
    int get(Point *p)
    {
        return p ? p->val : 0;
    }
    void pull(Point *p)
    {
        if (p)
            p->val = get(p->left) + get(p->right);
    }

public:
    void insert(Point *&p, int l, int r, int idx, int cnt)
    {
        if (!p)
            p = new Point();
        if (l == r)
        {
            p->val += cnt;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            insert(p->left, l, mid, idx, cnt);
        else
            insert(p->right, mid + 1, r, idx, cnt);
        pull(p);
    }
    int query(Point *p, int l, int r, int L, int R)
    {
        if (!p || r < L || l > R)
            return 0;
        if (L <= l && r <= R)
            return get(p);
        int mid = (l + r) >> 1;
        return query(p->left, l, mid, L, R) + query(p->right, mid + 1, r, L, R);
    }
    int kth(Point *p, int l, int r, int k)
    {
        if (!p || get(p) < k)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        if (get(p->left) > k)
            return kth(p->left, l, mid, k);
        return kth(p->right, mid + 1, r, k - get(p->left));
    }
    Point *merge(Point *p1, Point *p2)
    {
        if (!p1 || !p2)
            return p1 ? p1 : p2;
        Point *p = new Point();
        p->left = merge(p1->left, p2->left);
        p->right = merge(p1->right, p2->right);
        pull(p);
        return p;
    }
    void split(Point *&a, Point *&b, int l, int r, int L, int R)
    {
        if (!a || r < L || l > R)
            return;
        b = new Point();
        if (L <= l && r <= R)
        {
            b = a;
            a = nullptr;
            return;
        }
        int mid = (l + r) >> 1;
        split(a->left, b->left, l, mid, L, R);
        split(a->right, b->right, mid + 1, r, L, R);
        pull(a);
        pull(b);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    SegmentTree Tree;
    Point *sets[MAXN];
    for (int i = 0; i < MAXN; i++)
        sets[i] = nullptr;
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        if (cnt > 0)
            Tree.insert(sets[1], RANGE_L, RANGE_R, i, cnt);
    }
    int id_cnt = 2;
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 2)
        {
            int p, x, q;
            cin >> p >> x >> q;
            Tree.insert(sets[p], RANGE_L, RANGE_R, q, x);
        }
        else if (opt == 3)
        {
            int p, x, y;
            cin >> p >> x >> y;
            cout << Tree.query(sets[p], RANGE_L, RANGE_R, x, y) << '\n';
        }
        else if (opt == 4)
        {
            int p, k;
            cin >> p >> k;
            cout << Tree.kth(sets[p], RANGE_L, RANGE_R, k) << '\n';
        }
        else if (opt == 1)
        {
            int p, t;
            cin >> p >> t;
            sets[p] = Tree.merge(sets[p], sets[t]);
            sets[t] = nullptr;
        }
        else if (opt == 0)
        {
            int p, x, y;
            cin >> p >> x >> y;
            Tree.split(sets[p], sets[id_cnt], RANGE_L, RANGE_R, x, y);
            ++id_cnt;
        }
    }
    return 0;
}