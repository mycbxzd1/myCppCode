#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
long long pow(long long a, long long b, long long m)
{
    long long ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
long long extgcd(long long a, long long b, long long& x, long long& y)
//求解ax+by=gcd(a, b)
//返回值为gcd(a, b)
{
    long long d = a;
    if(b)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else x = 1, y = 0;
    return d;
}
long long mod_inverse(long long a, long long m)
//求解a关于模上m的逆元
//返回-1表示逆元不存在
{
    long long x, y;
    long long d = extgcd(a, m, x, y);
    return d == 1 ? (m + x % m) % m : -1;
}

long long Mul(long long n, long long pi, long long pk)//计算n! mod pk的部分值  pk为pi的ki次方
//算出的答案不包括pi的幂的那一部分，即第二部分  
{
    if(!n)return 1;
    long long ans = 1;
    if(n / pk)//第一部分  
    {
        for(long long i = 2; i <= pk; i++) //求出循环节乘积
            if(i % pi)ans = ans * i % pk;
        ans = pow(ans, n / pk, pk); //循环节次数为n / pk
    }
    for(long long i = 2; i <= n % pk; i++)//第一部分中多余的后半部分  
        if(i % pi)ans = ans * i % pk;
    return ans * Mul(n / pi, pi, pk) % pk;//递归求解第三部分  
}

long long C(long long n, long long m, long long p, long long pi, long long pk)//计算组合数C(n, m) mod pk的值 pk为pi的ki次方
{
    if(m > n)return 0;
    long long a = Mul(n, pi, pk), b = Mul(m, pi, pk), c = Mul(n - m, pi, pk);
    long long k = 0, ans;//k为pi的幂值
    for(long long i = n; i; i /= pi)k += i / pi;//算上递归部分没有计算的pi^(n/pi)  
    for(long long i = m; i; i /= pi)k -= i / pi;
    for(long long i = n - m; i; i /= pi)k -= i / pi;
    ans = a * mod_inverse(b, pk) % pk * mod_inverse(c, pk) % pk * pow(pi, k, pk) % pk;//ans就是n! mod pk的值
    ans = ans * (p / pk) % p * mod_inverse(p / pk, pk) % p;//此时用剩余定理合并解 
    return ans;
}

long long Lucas(long long n, long long m, long long p)
{
    long long x = p;
    long long ans = 0;
    for(long long i = 2; i <= p; i++)
    {
        if(x % i == 0)
        {
            long long pk = 1;
            while(x % i == 0)pk *= i, x /= i;
            ans = (ans + C(n, m, p, i, pk)) % p;
        }
    }
    return ans;
}

int main()
{
    long long n, m, p;
    cin >> n >> m >> p;
    cout<<Lucas(n, m, p)<<endl;
    return 0;
}