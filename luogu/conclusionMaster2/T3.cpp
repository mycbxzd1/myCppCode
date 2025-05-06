#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const ll BASE = 91138233;

struct SegTree
{
    struct Node
    {
        int l, r;
        ll h;
        bool flip;
    };
    vector<Node> t;
    vector<ll> *ppow, *pall1;

    SegTree(int n, vector<ll> &pow_, vector<ll> &all1_) : t(4 * n + 4), ppow(&pow_), pall1(&all1_)
    {
        build(1, 1, n);
    }

    void build(int o, int l, int r)
    {
        t[o].l = l;
        t[o].r = r;
        t[o].flip = false;
        if (l == r)
        {
            t[o].h = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
        pull(o);
    }

    void pull(int o)
    {
        int m = t[o << 1].r - t[o << 1].l + 1;
        t[o].h = (t[o << 1].h + t[o << 1 | 1].h * (*ppow)[m]) % MOD;
    }

    void apply_flip(int o)
    {
        int len = t[o].r - t[o].l + 1;
        t[o].h = (((*pall1)[len] - t[o].h) % MOD + MOD) % MOD;
        t[o].flip = !t[o].flip;
    }

    void push(int o)
    {
        if (t[o].flip)
        {
            apply_flip(o << 1);
            apply_flip(o << 1 | 1);
            t[o].flip = false;
        }
    }

    void update_flip(int o, int L, int R)
    {
        if (t[o].r < L || t[o].l > R)
            return;
        if (L <= t[o].l && t[o].r <= R)
        {
            apply_flip(o);
            return;
        }
        push(o);
        update_flip(o << 1, L, R);
        update_flip(o << 1 | 1, L, R);
        pull(o);
    }
    pair<ll, int> query_hash(int o, int L, int R)
    {
        if (t[o].r < L || t[o].l > R)
            return {0, 0};
        if (L <= t[o].l && t[o].r <= R)
        {
            int len = t[o].r - t[o].l + 1;
            return {t[o].h, len};
        }
        push(o);
        auto left = query_hash(o << 1, L, R);
        auto right = query_hash(o << 1 | 1, L, R);
        ll h = (left.first + right.first * (*ppow)[left.second]) % MOD;
        return {h, left.second + right.second};
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;
    if (k == 2)
    {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<ll> ppow(n + 1), pall1(n + 1);
        ppow[0] = 1;
        for (int i = 1; i <= n; i++)
            ppow[i] = (ppow[i - 1] * BASE) % MOD;
        pall1[0] = 0;
        for (int i = 1; i <= n; i++)
            pall1[i] = (pall1[i - 1] + ppow[i - 1]) % MOD;
        SegTree st(n, ppow, pall1);
        function<void(int, int, int)> init = [&](int o, int l, int r)
        {
            if (l == r)
            {
                st.t[o].h = a[l] % 2;
                return;
            }
            int m = (l + r) >> 1;
            init(o << 1, l, m);
            init(o << 1 | 1, m + 1, r);
            st.pull(o);
        };
        init(1, 1, n);
        while (q--)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int L, R, c;
                cin >> L >> R >> c;
                if (c % 2 == 1)
                    st.update_flip(1, L, R);
            }
            else
            {
                int l1, r1, l2, r2;
                cin >> l1 >> r1 >> l2 >> r2;
                auto h1 = st.query_hash(1, l1, r1).first;
                auto h2 = st.query_hash(1, l2, r2).first;
                cout << (h1 == h2 ? "Yes\n" : "No\n");
            }
        }
        return 0;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int L, R, c;
            cin >> L >> R >> c;
            c %= k;
            for (int i = L; i <= R; i++)
                a[i] = (a[i] + c) % k;
        }
        else
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            bool eq = true;
            for (int i = 0; i <= r1 - l1; i++)
            {
                if (a[l1 + i] != a[l2 + i])
                {
                    eq = false;
                    break;
                }
            }
            cout << (eq ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
