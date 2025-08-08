#include <bits/stdc++.h>
#define ll long long
using namespace std;

class IO {
private:
    void _read(int &x) {
        x = 0;
        char ch = getchar();
        bool neg = false;
        while (ch < '0' || ch > '9') {
            if (ch == '-') neg = true;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        if (neg) x = -x;
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

    void _write(const string &x) {
        for (char c : x) putchar(c);
    }

public:
    IO() {
        ios::sync_with_stdio(false); // 改为 false，避免与 `getchar` 等混用导致问题
        cin.tie(nullptr); // 更常用的绑定方式，`nullptr` 更清晰
    }

    template <typename T>
    void read(T &x) {
        _read(x);
    }

    template <typename T>
    void write(const T &x) {
        _write(x);
    }

    void newline() {
        putchar('\n');
    }
} io;

const int MAXN = 1e3 + 5;
int T, n, a[MAXN][MAXN];

int main() {
    freopen("atom.in", "r", stdin);
    freopen("atom.out", "w", stdout);

    io.read(T);
    while (T--) {
        io.read(n);

        if (n % 2 == 1) {
            io.write("No");
            io.newline();
            continue;
        }

        io.write("Yes");
        io.newline();

        // 清空矩阵（用 memset 替代双重 for 循环，效率更高）
        memset(a, 0, sizeof(a));

        // 构造符合要求的矩阵
        for (int k = 1; k <= n / 2; k += 2) {
            for (int i = k; i <= n - k + 1; i++) {
                a[k][i] = a[n - k + 1][i] = a[i][k] = a[i][n - k + 1] = 1;
            }
        }

        // 输出矩阵
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                io.write(a[i][j]);
                io.write(" ");
            }
            io.newline();
        }
    }
    return 0;
}
