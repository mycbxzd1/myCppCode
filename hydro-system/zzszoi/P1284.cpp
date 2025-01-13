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
const int N=1005,INF=0x3f3f3f3f,mod=1e9+7;
int n,m,a[N],b[N],c[N],f[N][N];
void add(int x,int y){
    while(x<=n+1){
        c[x]=(c[x]+y)%mod;
        x+=x&-x;
    }
}

int ask(int x){
    int ans=0;
    while(x){
        ans=(ans+c[x])%mod;
        x-=x&-x;
    }
    return ans;
}
int num=0;
int main(){
    int T;io.read(T);
    while(T--){
        
        io.read(n,m);
        for(int i=1;i<=n;i++)io.read(a[i]);
        memcpy(b,a,sizeof(a));
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b+1;
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=m;i++){
            memset(c,0,sizeof(c));
            add(1,f[i-1][0]);
            for(int j=1;j<=n;j++){
                f[i][j]=ask(a[j]-1);
                add(a[j],f[i-1][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=(ans+f[m][i])%mod;
        io.write("Case #",++num,": ",ans,"\n");
    }
    return 0;
}
