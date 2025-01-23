#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}  
int main() {
    ll a,b,x,y;
    cin>>a>>b;
    ll d = exgcd(a,b,x,y);
    cout<<(x%b+b)%b<<endl;
    return 0;
}
