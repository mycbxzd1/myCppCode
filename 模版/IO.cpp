#include <bits/stdc++.h>
using namespace std;

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
    // 构造函数：自动初始化同步和绑定
    IO() {
        ios::sync_with_stdio(1);
        cin.tie(&cout); // 确保绑定
    }

    // 统一的读取接口
    template <typename T>
    void read(T &x) {
        _read(x);
    }

    template <typename T>
    void read(vector<T> &v, int n) {
        _read(v, n);
    }

    // 统一的写出接口
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

    // 输出换行
    void newline() {
        putchar('\n');
    }
};

int main() {
    IO io;

    // 测试整数
    int n;
    io.read(n);
    io.write(n);
    io.newline();

    // 测试浮点数（动态精度传参）
    double d;
    io.read(d);
    io.write(d, 2); // 输出2位小数
    io.newline();
    io.write(d, 4); // 输出4位小数
    io.newline();

    // 测试字符串
    string s;
    io.read(s);
    io.write(s);
    io.newline();

    // 测试容器
    vector<int> v;
    io.read(v, n); // 读取n个元素
    io.write(v);
    io.newline();

    return 0;
}
