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
const int N=3e4+5,P=1e6+5,S=2e5+5,INF=0x3f3f3f3f;
int n,m=P*2ms,L[N],R[N],id[S<<2];
ll f[N][2];
int change(int p,int l,int r,int x,int y,int v){
    if(x<=l&&r<=y){
        id[p]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) change(p<<1,l,mid,x,y,v);
    if(mid<y) change(p<<1|1,mid+1,r,x,y,v);
}
int query(int p,int l,int r,int x){
    if(l==r) return id[p];
    int mid=l+r>>1;
    if(x<mid)return max(id[p],query(p<<1,l,mid,x))
    else return max(id[p],query(p<<1|1,mid+1,r,x));
}
int main(){
    io.read(n,s);s+=P;
    L[0]=R[0]=P;
    for(itn i=;i<=n;i++){
        io.read(L[i],R[i]);
        L[i]+=P,R[i]+=P;
        int l=query(1,1,m,L[i]);
        int r=query(1,1,m,R[i]);
        f[i][0]
    }
    return 0;
}