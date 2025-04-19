#include<bits/stdc++.h>
using namespace std;
const long long N=400005;

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

long long n,k,idx,ans,p;
long long hd[N],ver[N],nxt[N],imp[N],dis[N],f[N];

void add(long long x,long long y){
    nxt[++idx]=hd[x];
    ver[idx]=y;
    hd[x]=idx;
}

void dfs(long long x,long long fa){
    f[x]=fa;
    if(dis[x]>dis[p]&&imp[x])p=x;
    for(long long i=hd[x];i;i=nxt[i]){
        long long y=ver[i];
        if(y==fa)continue;
        dis[y]=dis[x]+1;
        dfs(y,x);
    }
}

int main(){
    int T;io.read(T);
    while(T--){
        io.read(n,k);
        idx=0,p=0;
        for(long long i=1;i<=n;i++)hd[i]=imp[i]=f[i]=dis[i]=0;
        for(long long i=1;i<=k;i++){
            int x;
            io.read(x);
            imp[x]=1;
        }
        for(long long i=1;i<n;i++){
            long long x,y;
            io.read(x,y);
            add(x,y);
            add(y,x);
        }
        dis[1]=0;
        dfs(1,0);
        dis[p]=0,idx=0,ans=-1;
        dfs(p,0);
        for(long long i=p;i;i=f[i]){
            ans++;
        }
        io.write((ans+1)/2);
        io.newline();
    }
    return 0;
}
