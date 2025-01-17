#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
const int N=1e8+5,INF=0x3f3f3f3f;
vector<int> pri;
bool not_prime[N];
int n;
void pre() {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i])pri.push_back(i);
        for (int pri_j : pri) {
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0)break;
        }
    }
}
/*
bool f[N];int prime[N],n;*/
/*void calc(){
    memset(f,0,sizeof(f));
    f[0]=f[1]=1;
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(!f[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
            f[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}*/
int main(){
    int q;io.read(n,q);
    pre();
    while(q--){
        int x;io.read(x);
        io.write(pri[x-1]);
        io.newline();
    }
    return 0;
}