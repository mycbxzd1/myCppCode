#include<bits/stdc++.h>
using namespace std;
const int maxn=1000019,INF=1e9;
class Treap {
private:
    int ch[maxn][2],val[maxn],dat[maxn],size[maxn],cnt[maxn],tot,root;
    int New(int v) {
        val[++tot]=v;
        dat[tot]=rand();
        size[tot]=1;
        cnt[tot]=1;
        return tot;
    }
    void update(int id) {
        size[id]=size[ch[id][0]]+size[ch[id][1]]+cnt[id];
    }
    void left_rotate(int &id) {
        int temp=ch[id][1];
        ch[id][1]=ch[temp][0];
        ch[temp][0]=id;
        id=temp;
        update(ch[id][0]);
        update(id);
    }
    void right_rotate(int &id) {
        int temp=ch[id][0];
        ch[id][0]=ch[temp][1];
        ch[temp][1]=id;
        id=temp;
        update(ch[id][1]);
        update(id);
    }
    void insert_node(int &id,int v) {
        if(!id) {
            id=New(v);
            return;
        }
        if(val[id]==v)cnt[id]++;
        else {
            if(v<val[id]) {
                insert_node(ch[id][0],v);
                if(dat[id]<dat[ch[id][0]])right_rotate(id);
            } else {
                insert_node(ch[id][1],v);
                if(dat[id]<dat[ch[id][1]])left_rotate(id);
            }
        }
        update(id);
    }
    void remove_node(int &id,int v) {
        if(!id)return;
        if(val[id]==v) {
            if(cnt[id]>1) {
                cnt[id]--;
                update(id);
                return;
            }
            if(!ch[id][0]&&!ch[id][1])id=0;
            else if(!ch[id][1]||dat[ch[id][0]]>dat[ch[id][1]]) {
                right_rotate(id);
                remove_node(ch[id][1],v);
            } else {
                left_rotate(id);
                remove_node(ch[id][0],v);
            }
            update(id);
        } else {
            if(v<val[id])remove_node(ch[id][0],v);
            else remove_node(ch[id][1],v);
        }
        update(id);
    }
    int get_by_rank(int id,int rank) {
        if(!id)return INF;
        if(rank<=size[ch[id][0]])return get_by_rank(ch[id][0],rank);
        else if(rank<=size[ch[id][0]]+cnt[id])return val[id];
        else return get_by_rank(ch[id][1],rank-size[ch[id][0]]-cnt[id]);
    }
    int get_precursor(int v) {
        int id=root,pre=-INF;
        while(id) {
            if(val[id]<v)pre=val[id],id=ch[id][1];
            else id=ch[id][0];
        }
        return pre;
    }
    int get_nextcursor(int v) {
        int id=root,next=INF;
        while(id) {
            if(val[id]>v)next=val[id],id=ch[id][0];
            else id=ch[id][1];
        }
        return next;
    }
public:
    Treap():tot(0),root(0){insert(-INF);insert(INF);}
    void insert(int v){insert_node(root,v);}
    void remove(int v){remove_node(root,v);}
    int get(int rank){return get_by_rank(root,rank+1);}
    int precursor(int v){return get_precursor(v);}
    int nextcursor(int v){return get_nextcursor(v);}
}treap;
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
void solve(){
    int op,x;cin>>op>>x;
    if(op==1)treap.insert(x);
    else if(op==2)treap.remove(x);
    else if(op==3)io.write(treap.precursor(x)),io.newline();
    else if(op==4)io.write(treap.nextcursor(x)),io.newline();
    else if(op==5)io.write(treap.get(x)),io.newline();
}
int main(){
    int T;cin>>T;
    while(T--)solve();
    return 0;
}