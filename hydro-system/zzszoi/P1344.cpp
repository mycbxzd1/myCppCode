#include <bits/stdc++.h>
using namespace std;
long long eular(long long n){
    long long ret = n;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ret = ret / i * (i - 1);
            while (n % i == 0)n /= i;
        }
    }
    if (n > 1)ret = ret / n * (n - 1);
    return ret;
}
int main(){
    long long n;
    long long ans = 0;
    while (cin >> n)
    {
        ans = eular(n) + n;
        for (long long i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i * i == n)
                    ans += eular(i) * i;
                else
                    ans += eular(i) * (n / i) + eular(n / i) * i;
            }
        }
        cout << ans << endl;
    }
}
