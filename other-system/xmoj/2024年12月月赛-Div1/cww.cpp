#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll ans,C[100000],W[100000];
vector<int>G[100000];
string S;
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
void dfs1(int n, int p) {
    if(S[n] == 'c') C[n]++;
    else W[n]++;
    for(auto c : G[n]) {
        if(c == p) continue;
        dfs1(c, n);
        C[n] += C[c];
        W[n] += W[c];
    }
}
void dfs2(int n, int p){
    if(S[n]=='w') {
        ll csum=C[0],wsum=W[0];
        for(auto c:G[n]) {
            ll cn=0,wn=0;
            if(c==p){
                cn=csum-C[n];
                wn=wsum-W[n];
            }
            else {
                cn=C[c];
                wn=W[c];
            }
            ans+=cn*(wsum-1-wn);
        }
    }
    for(auto c:G[n]){
        if(c==p) continue;
        dfs2(c,n);
    }
}
int main(){
    freopen("cww.in","r",stdin);
    freopen("cww.out","w",stdout);
    io.read(N);io.read(S);
    for(int i = 0; i < N - 1; i++) {
        int a, b;io.read(a),io.read(b),a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    cout<<ans<<endl;
}