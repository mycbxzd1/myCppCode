#include<bits/stdc++.h>
using namespace std;
const int MOD=100000000;
class IO {
private:
    // 处理整数类型的快速输入
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

    // 处理浮点数类型的快速输入
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

    // 处理字符串类型的快速输入
    void _read(string &x) {
        x.clear();
        char ch = getchar();
        while (isspace(ch)) ch = getchar();
        while (!isspace(ch) && ch != EOF) {
            x.push_back(ch);
            ch = getchar();
        }
    }

    // 处理整数类型的快速输出
    void _write(int x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x >= 10) _write(x / 10);
        putchar(x % 10 + '0');
    }

    // 处理浮点数类型的快速输出，支持动态精度
    void _write(double x, int precision) {
        cout << fixed << setprecision(precision) << x;
    }

    // 处理字符串类型的快速输出
    void _write(const string &x) {
        for (char c : x) putchar(c);
    }

    // 处理容器的快速输入
    template <typename T>
    void _read(vector<T> &v, int n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) _read(v[i]);
    }

    // 处理容器的快速输出
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

    void DPinput(DP &dp){
        read(dp.m),read(dp.n);
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                read(dp.grid[i][j])
                dp.state[i]=(dp.state[i]<<1)+dp.grid[i][j];
            }
        }
    }
}io;
class DP {
private:
    int m,n;
    long long f[13][1<<12],state[13],valid[1<<12];
    int grid[13][13];
    bool is_valid(int x) {
        return !(x&(x>>1))&&!(x&(x<<1));
    }
    void compute_valid_states() {
        for(int i=0;i<(1<<n);i++) {
            valid[i]=is_valid(i);
        }
    }
    void initialize_dp() {
        for(int i=0;i<(1<<n);i++) {
            if(valid[i]&&(i&state[1])==i) {
                f[1][i]=1;
            }
        }
    }
    void compute_dp() {
        for(int x=2;x<=m;x++) {
            for(int j=0;j<(1<<n);j++) {
                if((j&state[x-1])==j&&valid[j]) {
                    for(int k=0;k<(1<<n);k++) {
                        if((k&state[x])==k&&valid[k]&&!(j&k)) {
                            f[x][k]=(f[x][k]+f[x-1][j])%MOD;
                        }
                    }
                }
            }
        }
    }
    int compute_result() {
        int ans=0;
        for(int i=0;i<(1<<n);i++) {
            ans=(ans+f[m][i])%MOD;
        }
        return ans;
    }
    friend class IO;
public:
    int solve() {
        compute_valid_states();
        initialize_dp();
        compute_dp();
        return compute_result();
    }
};

int main() {
    DP dp;
    io.DPinput(dp);
    cout<<dp.solve()<<endl;
    return 0;
}
