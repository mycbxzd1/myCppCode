#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=60,S=600;
int n;
class bigInt {
private:
    int a[S]{}, len=0;
public:
    bigInt() = default;
    void set(int x) {
        len=0;
        while(x) a[++len]=x%10, x/=10;
    }
    bigInt operator/(int x)const {
        bigInt ans;
        int num=0;
        for(int i=len;i;i--) {
            num=num*10+a[i];
            ans.a[i]=num/x, num%=x;
            if(!ans.len&&ans.a[i])ans.len=i;
        }
        return ans;
    }
    bigInt operator+(const bigInt&x)const {
        bigInt ans;
        for(int i=1;i<=max(len,x.len);i++) {
            ans.a[i]+=a[i]+x.a[i];
            ans.a[i+1]=ans.a[i]/10, ans.a[i]%=10;
        }
        ans.len=max(len,x.len);
        if(ans.a[ans.len+1])++ans.len;
        return ans;
    }
    bigInt operator*(const bigInt&x)const {
        bigInt ans;
        for(int i=1;i<=len;i++)
            for(int j=1;j<=x.len;j++) {
                ans.a[i+j-1]+=a[i]*x.a[j];
                ans.a[i+j]+=ans.a[i+j-1]/10;
                ans.a[i+j-1]%=10;
            }
        ans.len=len+x.len-1;
        if(ans.a[ans.len+1])++ans.len;
        return ans;
    }
    friend ostream& operator<<(ostream& out, const bigInt& x) {
        for(int i=x.len;i;i--) out<<x.a[i];
        return out;
    }
};

bigInt f[N], p[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    auto C=[&](int x,int y){bigInt ans;ans.set(1);for(int i=y,j=1;j<=x;i--,j++){bigInt tmp;tmp.set(i);ans=ans*tmp/j;}return ans;};
    for(int i=1;i<=50;i++) p[i].set((1ll<<i)-1);
    f[1].set(1), f[2].set(1);
    for(int i=3;i<=50;i++)
        for(int j=1;j<i;j++)
            f[i]=f[i]+C(j-1,i-2)*f[j]*f[i-j]*p[j];
    while(cin>>n&&n) cout<<f[n]<<'\n';
}
