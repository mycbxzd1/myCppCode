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
struct rec{ int L, P, S; } a[110];
int n, m;
int f[110][16010], q[16010];
bool operator <(rec a, rec b) {
	return a.S < b.S;
}
int calculate(int i, int k) {
	return f[i - 1][k] - a[i].P * k;
}
int main()  {
	io.read(n, m);
	for (int i = 1; i <= m; i++)io.read(a[i].L, a[i].P, a[i].S);
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++) {
		int l = 1, r = 0;
		for (int k = max(0, a[i].S - a[i].L); k <= a[i].S - 1; k++) {
			while (l <= r && calculate(i, q[r]) <= calculate(i, k)) r--;
			q[++r] = k;
		}
		for (int j = 1; j <= n; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (j >= a[i].S) {
				while (l <= r && q[l] < j - a[i].L) l++;
				if (l <= r) f[i][j] = max(f[i][j], calculate(i, q[l]) + a[i].P * j);
			}
		}
	}
	cout << f[m][n] << endl;
}