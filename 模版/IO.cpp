#include <bits/stdc++.h>
using namespace std;

class IO {
private:
    void _read(int &x) {
        x=0;char ch=getchar();bool f=0;
        while(ch<'0'||ch>'9'){
            if(ch=='-')f=1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<3)+(x<<1)+(ch^48);
            ch=getchar();
        }
        if(f)x=-x;
    }

    void _read(char &x) {
        do {
            x=getchar();
        } while(isspace(x));
    }

    void _read(string &x) {
        x.clear();
        char ch;
        do {
            ch=getchar();
        } while(isspace(ch));
        while(!isspace(ch)&&ch!=EOF) {
            x.push_back(ch);
            ch=getchar();
        }
    }

    void _write(int x) {
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x>=10)_write(x/10);
        putchar(x%10+'0');
    }

    void _write(const char *s) {
        while(*s) putchar(*s++);
    }

    template<typename T>
    void _write(const T &x) {
        cout<<x;
    }

public:
    IO(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    // 提供统一的 read 接口
    template<typename T>
    void read(T &x){
        _read(x);
    }

    template<typename T,typename... Args>
    void read(T &x,Args&... args){
        _read(x);
        read(args...);
    }

    template<typename T>
    void write(const T &x){
        _write(x);
    }

    template<typename T,typename... Args>
    void write(const T &x,const Args&... args){
        _write(x);
        write(args...);
    }

    void newline(){
        putchar('\n');
    }
} io;

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
