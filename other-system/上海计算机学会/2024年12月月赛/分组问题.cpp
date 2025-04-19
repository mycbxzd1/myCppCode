#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
class IO{
private:
    void _read(int &x){
        x=0;
        char ch=getchar();
        bool f=0;
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
    void _read(double &x){
        x=0;
        char ch=getchar();
        bool f=0;
        while((ch<'0'||ch>'9')&&ch!='.'&&ch!='-'){
            if(ch=='-')f=1;
            ch=getchar();
        }
        bool is_decimal=false;
        double frac=0.1;
        while((ch>='0'&&ch<='9')||ch=='.'){
            if(ch=='.'){
                is_decimal=true;
            }else{
                if(is_decimal){
                    x+=(ch-'0')*frac;
                    frac*=0.1;
                }else{
                    x=x*10+(ch-'0');
                }
            }
            ch=getchar();
        }
        if(f)x=-x;
    }
    void _read(string &x){
        x.clear();
        char ch=getchar();
        while(isspace(ch))ch=getchar();
        while(!isspace(ch)&&ch!=EOF){
            x.push_back(ch);
            ch=getchar();
        }
    }
    void _write(int x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x>=10)_write(x/10);
        putchar(x%10+'0');
    }
    void _write(double x,int precision){
        cout<<fixed<<setprecision(precision)<<x;
    }
    void _write(const string &x){
        for(char c:x)putchar(c);
    }
    template<typename T>
    void _read(vector<T> &v,int n){
        v.resize(n);
        for(int i=0;i<n;++i)_read(v[i]);
    }
    template<typename T>
    void _write(const vector<T> &v){
        for(const auto &elem:v){
            _write(elem);
            putchar(' ');
        }
    }
public:
    IO(){
        ios::sync_with_stdio(1);
        cin.tie(&cout);
    }
    template<typename T>
    void read(T &x){
        _read(x);
    }
    template<typename T>
    void read(vector<T> &v,int n){
        _read(v,n);
    }
    template<typename T>
    void write(const T &x){
        _write(x);
    }
    void write(double x,int precision=6){
        _write(x,precision);
    }
    template<typename T>
    void write(const vector<T> &v){
        _write(v);
    }
    void newline(){
        putchar('\n');
    }
}io;
long long quick_pow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b=(b>>1);
    }
    return ans;
}
long long mul(long long a,long long b){return a*b%mod;}
long long add(long long a,long long b){
    long long ret=a+b;
    if(ret>=mod)ret-=mod;
    return ret;
}
void get(int x,int n,const vector<int> &divisors,vector<int> &val){
    int ret=n/divisors[x];
    for(int i=0;i<x;++i)if(divisors[i]%divisors[x]==0)ret-=val[i];
    val[x]=ret;
}
int main(){
    int n;
    io.read(n);
    vector<int> ans(n+1);ans[1]=0;
    vector<vector<int>> divs(n+1);
    for(int i=1;i<=n;++i)for(int j=i;j<=n;j+=i)divs[j].push_back(i);
    for(int i=1;i<=n;++i){
        vector<int> &divisors=divs[i];
        reverse(divisors.rbegin(),divisors.rend());
        vector<int> val(divisors.size());
        long long sum=0;
        for(int j=0;j<(int)divisors.size();++j){
            get(j,n,divisors,val);
            int d=divisors[j];
            if(d==i)continue;
            sum=add(sum,mul(val[j],ans[d]+1));
        }
        ans[i]=mul(sum+val[0],quick_pow(n-val[0],mod-2));
    }
    for(int i=1;i<=n;++i)io.write(ans[i]),io.write(" ");
}
