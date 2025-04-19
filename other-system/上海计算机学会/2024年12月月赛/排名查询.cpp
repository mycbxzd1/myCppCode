#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
class segtree
{
private:
    vector<T> tree;
    int n,root,n4,end;

    T range_sum(int l,int r,int cl,int cr,int p)
    {
        if(l<=cl&&cr<=r)return tree[p];
        int m=cl+(cr-cl)/2;
        T sum=0;
        if(l<=m)
            sum+=range_sum(l,r,cl,m,p*2);
        if(r>m)
            sum+=range_sum(l,r,m+1,cr,p*2+1);
        return sum;
    }

    void point_add(int i,T val,int cl,int cr,int p)
    {
        if(cl==cr)
        {
            tree[p]+=val;
            return;
        }
        int m=cl+(cr-cl)/2;
        if(i<=m)point_add(i,val,cl,m,p*2);
        else point_add(i,val,m+1,cr,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }

public:
    explicit segtree<T>(int sizet)
    {
        n=sizet;
        n4=n*4;
        tree=vector<T>(n4,0);
        end=n-1;
        root=1;
    }

    T range_sum(int l,int r){return range_sum(l,r,0,end,root);}
    void point_add(int i,T val){point_add(i,val,0,end,root);}
};
class IO {
private:
    void _read(int &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = getchar();
        }
        if (f) x = -x;
    }
    void _read(double &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while ((ch < '0' || ch > '9') && ch != '.' && ch != '-') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        bool is_decimal = false;
        double frac = 0.1;
        while ((ch >= '0' && ch <= '9') || ch == '.') {
            if (ch == '.') {
                is_decimal = true;
            } else {
                if (is_decimal) {
                    x += (ch - '0') * frac;
                    frac *= 0.1;
                } else {
                    x = x * 10 + (ch - '0');
                }
            }
            ch = getchar();
        }
        if (f) x = -x;
    }
    void _read(string &x) {
        x.clear();
        char ch = getchar();
        while (isspace(ch)) ch = getchar();
        while (!isspace(ch) && ch != EOF) {
            x.push_back(ch);
            ch = getchar();
        }
    }
    void _write(int x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x >= 10) _write(x / 10);
        putchar(x % 10 + '0');
    }
    void _write(double x, int precision) {
        cout << fixed << setprecision(precision) << x;
    }
    void _write(const string &x) {
        for (char c : x) putchar(c);
    }
    template <typename T>
    void _read(vector<T> &v, int n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) _read(v[i]);
    }
    template <typename T>
    void _write(const vector<T> &v) {
        for (const auto &elem : v) {
            _write(elem);
            putchar(' ');
        }
    }
public:
    IO() {
        ios::sync_with_stdio(1);
        cin.tie(&cout);
    }
    template <typename T>
    void read(T &x) {
        _read(x);
    }
    template <typename T>
    void read(vector<T> &v, int n) {
        _read(v, n);
    }
    template <typename T>
    void write(const T &x) {
        _write(x);
    }
    void write(double x, int precision = 6) {
        _write(x, precision);
    }
    template <typename T>
    void write(const vector<T> &v) {
        _write(v);
    }
    void newline() {
        putchar('\n');
    }
}io;
const int maxn = 2e6 + 15;
int a[maxn], tmp[maxn];
int lef[maxn], rig[maxn];
int milef[maxn], mirig[maxn];
int rnk[maxn];
signed main()
{
    int n, q;io.read(n);io.read(q);
    for (int i = 1; i <= n; i++)io.read(a[i]),tmp[i] = a[i];
    sort(tmp + 1, tmp + 1 + n);
    int len = unique(tmp + 1, tmp + 1 + n) - (tmp + 1);
    for(int i = 1; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp;
    segtree<int> a1(n + 10), a2(n + 10), a3(n + 10), a4(n + 10);
    for(int i = 1; i <= n; i++) {
        lef[i] = a1.range_sum(a[i] + 1, n);
        milef[i] = a3.range_sum(0, a[i] - 1);
        a1.point_add(a[i], 1);
        a3.point_add(a[i], 1);
    }
    for(int i = n; i >= 1; i--) {
        rig[i] = a2.range_sum(a[i] + 1, n);
        mirig[i] = a4.range_sum(0, a[i] - 1);
        a2.point_add(a[i], 1);
        a4.point_add(a[i], 1);
    }
    for(int i = 1; i <= n; i++)rnk[i] = lef[i] + rig[i] + 1;
    while (q--)
    {
        int k, r_;io.read(k);io.read(r_);
        int l = 0, r = n, ans = 0;
        while(l < r) {
            int m = (l + r) / 2;
            int can = rnk[k] - min(m, lef[k]) - min(m, rig[k]);
            if(can <= r_) {
                r = m;
                ans = r;
            } else {
                l = m + 1;
            }
        }
        io.write(ans);
        io.newline();
    }
}