#include<bits/stdc++.h>
#define int long long
using namespace std;

class IO {
private:
    void _read(int &x) {
        x=0;char ch=getchar();bool f=0;
        while(ch!=EOF && (ch<'0'||ch>'9')){
            if(ch=='-')f=1;
            ch=getchar();
        }
        while(ch!=EOF && ch>='0'&&ch<='9'){
            x=(x<<3)+(x<<1)+(ch^48);
            ch=getchar();
        }
        if(f)x=-x;
    }
    void _write(int x) {
        if(x<0){putchar('-');x=-x;}
        if(x>=10)_write(x/10);
        putchar(x%10+'0');
    }
public:
    IO() {ios::sync_with_stdio(false);cin.tie(nullptr);}
    template<typename T>void read(T &x) {_read(x);}
    template<typename T>void write(const T &x) {_write(x);}
    void newline() {putchar('\n');}
}io;

const int MOD=998244353;

int power_mod(int a,int b,int mod){
    int res=1;a%=mod;
    while(b>0){
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}

class Fraction {
private:
    int numerator,denominator;
public:
    Fraction(int num=0,int den=1) {
        num = (num % MOD + MOD) % MOD;
        den = (den % MOD + MOD) % MOD;
        // 假设输入数据不会导致 den=0
        numerator = num;
        denominator = den;
    }
    
    Fraction operator+(const Fraction& other)const{
        int num=(numerator*other.denominator+other.numerator*denominator)%MOD;
        int den=(denominator*other.denominator)%MOD;
        return Fraction(num,den);
    }
    Fraction operator-(const Fraction& other)const{
        int num=(numerator*other.denominator - other.numerator*denominator)%MOD;
        num = (num+MOD)%MOD;
        int den=(denominator*other.denominator)%MOD;
        return Fraction(num,den);
    }
    Fraction operator*(const Fraction& other)const{
        int num=(numerator*other.numerator)%MOD;
        int den=(denominator*other.denominator)%MOD;
        return Fraction(num,den);
    }
    Fraction operator/(const Fraction& other)const{
        int inv=power_mod(other.denominator,MOD-2,MOD);
        int num=(numerator*other.numerator)%MOD;
        int den=(denominator*inv)%MOD;
        return Fraction(num,den);
    }
    int value()const{
        return (numerator * power_mod(denominator,MOD-2,MOD))%MOD;
    }
};

int f[1000]={1,1,1};
signed main(){
    for(int i=3;i<=600;++i)f[i]=(f[i-1]*2)%MOD;
    int n;io.read(n);
    int tmp=1;
    Fraction ans(0,1);
    while(n>0){
        if(f[tmp]<=n){
            n-=f[tmp];
            Fraction term((tmp*f[tmp])%MOD,1);
            ans=ans+term;
        }else{
            Fraction term((n*tmp)%MOD,1);
            ans=ans+term;
            n=0;
        }
        tmp++;
    }
    io.write(ans.value());
    io.newline();
    return 0;
}