#include<bits/stdc++.h>
using namespace std;
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
int n, a[100010], c[100010], q[100010];
long long m, f[100010];
multiset<long long> s;
int main() {
	io.read(n, m);
	for (int i = 1; i <= n; i++) {
		io.read(a[i]);
		if (a[i] > m) {
			io.write("-1");
			return 0;
		}
	}
	long long sum = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		sum += a[i];
		while (sum > m) sum -= a[j + 1], j++;
		c[i] = j;
	}
	int l = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		while (l <= r && q[l] <= c[i])s.erase(f[q[l]] + a[q[l + 1]]),l++;
		while (l <= r && a[q[r]] <= a[i])s.erase(f[q[r - 1]] + a[q[r]]),r--;
		if (l <= r) s.insert(f[q[r]] + a[i]);
		q[++r] = i;
		f[i] = f[c[i]] + a[q[l]];
		if (!s.empty()) f[i] = min(f[i], *s.begin());
	}
	io.write(f[n],"\n");
}