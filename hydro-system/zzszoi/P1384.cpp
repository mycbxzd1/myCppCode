#include <bits/stdc++.h>
using namespace std;
const int maxT = 4000105;

int n, m, t, ti, ans = 1e9, l = 1, r, cnt[maxT], sum[maxT], q[maxT], f[maxT];
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
double getSlope(int u, int v) { 
    return (double)(f[v] + sum[v] - f[u] - sum[u]) / (cnt[u] == cnt[v] ? 1e-9 : cnt[v] - cnt[u]); 
}

int main()
{
    io.read(n, m);
    for (int i = 1; i <= n; i++)io.read(ti),t = max(t, ti),cnt[ti]++,sum[ti] += ti;
    for (int i = 1; i < t + m; i++)cnt[i] += cnt[i - 1],sum[i] += sum[i - 1];
    for (int i = 0; i < t + m; i++){
        if (i - m >= 0){
            while (l < r && getSlope(q[r - 1], q[r]) >= getSlope(q[r], i - m))r--;
            q[++r] = i - m;
        }
        while (l < r && getSlope(q[l], q[l + 1]) <= i)l++;
        f[i] = cnt[i] * i - sum[i];
        if (l <= r)f[i] = min(f[i], f[q[l]] + (cnt[i] - cnt[q[l]]) * i - (sum[i] - sum[q[l]]));
    }
    for (int i = t; i < t + m; i++)ans = min(ans, f[i]);
    cout<<ans<<endl;
    return 0;
}