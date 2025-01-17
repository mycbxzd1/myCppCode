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
const int MAXN = 1000005;
long long f[MAXN], sumT[MAXN], sumC[MAXN], s, q[MAXN], n;
int search(long long k, int l, int r)
{
    int L = l, R = r;
    while (L < R)
    {
        int mid = (L + R) >> 1;
        if ((f[q[mid + 1]] - f[q[mid]]) <= k * (sumC[q[mid + 1]] - sumC[q[mid]]))
            L = mid + 1;
        else
            R = mid;
    }
    return q[L];
}
int main()
{
    io.read(n,s);
    for (int i = 1; i <= n; i++)
    {
        int t, c;io.read(t,c);
        sumT[i] = sumT[i - 1] + t;
        sumC[i] = sumC[i - 1] + c;
    }
    int l = 1, r = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = search(sumT[i] + s, l, r);
        f[i] = f[p] - (s + sumT[i]) * sumC[p] + sumT[i] * sumC[i] + s * sumC[n];
        while (l < r && (f[q[r]] - f[q[r - 1]]) * (sumC[i] - sumC[q[r]]) >= (f[i] - f[q[r]]) * (sumC[q[r]] - sumC[q[r - 1]]))
            r--;
        q[++r] = i;
    }
    io.write(f[n]);
    io.newline();
    return 0;
}
