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
    void _read(long long &x) {
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
int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<long long> a(7);
    long long N = 0;
    for(int i = 0; i < 7; i++)io.read(a[i]), N += a[i];
    if(N < 7){
        cout << "0.000\n";
        return 0;
    }
    for(int i = 0; i < 7; i++){
        if(a[i] == 0){
            cout << "0.000\n";
            return 0;
        }
    }
    long double numerator = 5040.0L;
    for(int i = 0; i < 7; i++)numerator *= (long double)(a[i]);
    long double denominator = 1.0L;
    for(int k = 0; k < 7; k++)denominator *= (long double)(N - k);
    long double prob_first_7_distinct = numerator / denominator; // <= 1
    long double expectation = (long double)(N - 6) * prob_first_7_distinct;
    cout << fixed << setprecision(3) << (long double)expectation << "\n";
    return 0;
}