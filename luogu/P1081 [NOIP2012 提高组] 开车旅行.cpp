#include<bits/stdc++.h>
using namespace std;
const int u=100010;
long long a[u][18][2],b[u][18][2],ansA,ansB,A,B;
int f[u][18][2],ans,n,m,t,i,j,k,h[u],g[u],go[u][2],x0,l,x,y;
struct rec{int x,y;};
set<rec> s;
set<rec>::iterator it,lt,rt;
class IO {
private:
    // 处理整数类型的快速输入
    void _read(int &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = getchar();
        }
        if (f) x = -x;
    }

    // 处理浮点数类型的快速输入
    void _read(double &x) {
        x = 0;
        char ch = getchar();
        bool f = 0;
        while ((ch < '0' || ch > '9') && ch != '.' && ch != '-') {
            if (ch == '-') f = 1;
            ch = getchar();
        }
        bool is_decimal = false;
        double frac = 0.1;
        while ((ch >= '0' && ch <= '9') || ch == '.') {
            if (ch == '.') {
                is_decimal = true;
            } else {
                if (is_decimal) {
                    x += (ch - '0') * frac;
                    frac *= 0.1;
                } else {
                    x = x * 10 + (ch - '0');
                }
            }
            ch = getchar();
        }
        if (f) x = -x;
    }

    // 处理字符串类型的快速输入
    void _read(string &x) {
        x.clear();
        char ch = getchar();
        while (isspace(ch)) ch = getchar();
        while (!isspace(ch) && ch != EOF) {
            x.push_back(ch);
            ch = getchar();
        }
    }

    // 处理整数类型的快速输出
    void _write(int x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        if (x >= 10) _write(x / 10);
        putchar(x % 10 + '0');
    }

    // 处理浮点数类型的快速输出，支持动态精度
    void _write(double x, int precision) {
        cout << fixed << setprecision(precision) << x;
    }

    // 处理字符串类型的快速输出
    void _write(const string &x) {
        for (char c : x) putchar(c);
    }

    // 处理容器的快速输入
    template <typename T>
    void _read(vector<T> &v, int n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) _read(v[i]);
    }

    // 处理容器的快速输出
    template <typename T>
    void _write(const vector<T> &v) {
        for (const auto &elem : v) {
            _write(elem);
            putchar(' ');
        }
    }

public:
    // 构造函数：自动初始化同步和绑定
    IO() {
        ios::sync_with_stdio(1);
        cin.tie(&cout); // 确保绑定
    }

    // 统一的读取接口
    template <typename T>
    void read(T &x) {
        _read(x);
    }

    template <typename T>
    void read(vector<T> &v, int n) {
        _read(v, n);
    }

    // 统一的写出接口
    template <typename T>
    void write(const T &x) {
        _write(x);
    }

    void write(double x, int precision = 6) {
        _write(x, precision);
    }

    template <typename T>
    void write(const vector<T> &v) {
        _write(v);
    }

    // 输出换行
    void newline() {
        putchar('\n');
    }
}io;
bool operator <(rec a,rec b)
{
	return a.y<b.y;
}
bool cmp(int a,int b)
{
	return abs(h[a]-h[i])<abs(h[b]-h[i])||abs(h[a]-h[i])==abs(h[b]-h[i])&&h[a]<h[b];
}

void solve(int s,int x0,long long &A,long long &B)
{
	A=B=k=0;
	for(int i=t;i>=0;i--)
	  if(f[s][i][k]&&a[s][i][k]+b[s][i][k]<=x0)
	  {
			x0-=a[s][i][k]+b[s][i][k];
			A+=a[s][i][k],B+=b[s][i][k];
			if(i==0) k^=1;
			s=f[s][i][k];
		}
}

int main()
{
	io.read(n);
	for(i=1;i<=n;i++)io.read(h[i]);
	for(i=n;i;i--)
	{
		rec New; New.x=i,New.y=h[i];
		s.insert(New);
		it=s.find(New);
		lt=it,rt=it,m=0;
		if(lt!=s.begin()) lt--,g[++m]=lt->x;
		if(lt!=s.begin()) lt--,g[++m]=lt->x;
		if(rt++,rt!=s.end())
		{
			g[++m]=rt->x;
			if(rt++,rt!=s.end()) g[++m]=rt->x;
		}
		sort(g+1,g+m+1,cmp);
		if(m) go[i][0]=g[1];
		if(m>1) go[i][1]=g[2];
	}
	for(i=1;i<=n;i++)
	{
		if(go[i][1]) f[i][0][0]=go[i][1],a[i][0][0]=abs(h[go[i][1]]-h[i]),b[i][0][0]=0;
		if(go[i][0]) f[i][0][1]=go[i][0],a[i][0][1]=0,b[i][0][1]=abs(h[go[i][0]]-h[i]);
	}
	t=(int)(log(n*1.0)/log(2.0)+0.001);
	for(i=1;i<=t;i++)
	  for(j=1;j<=n;j++)
	    for(k=0;k<=1;k++)
			{
				if(i==1) l=k^1; else l=k;
				if(f[j][i-1][k]) f[j][i][k]=f[f[j][i-1][k]][i-1][l];
				if(f[j][i][k])
				{
					a[j][i][k]=a[j][i-1][k]+a[f[j][i-1][k]][i-1][l];
					b[j][i][k]=b[j][i-1][k]+b[f[j][i-1][k]][i-1][l];
				}
			}
	io.read(x0);
	ansA=1,ansB=0;
	for(i=1;i<=n;i++)
	{
		solve(i,x0,A,B);
		if(!B) A=1;
		if(A*ansB<ansA*B||A*ansB==ansA*B&&h[i]>h[ans]) ansA=A,ansB=B,ans=i;
	}
	io.write(ans),io.newline();
	io.read(m);
	for(i=1;i<=m;i++)
	{
		io.read(x),io.read(y);
		solve(x,y,A,B);
        io.write(A),io.write(" "),io.write(B),io.newline();
	}
	return 0;
}