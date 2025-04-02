#include <bits/stdc++.h>
using namespace std;
class IO
{
private:
	void _read(int &x)
	{
		x = 0;
		char ch = getchar();
		bool f = 0;
		while (ch < '0' || ch > '9')
		{
			if (ch == '-')
				f = 1;
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9')
		{
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = getchar();
		}
		if (f)
			x = -x;
	}

	void _read(char &x)
	{
		do
		{
			x = getchar();
		} while (isspace(x));
	}

	void _read(string &x)
	{
		x.clear();
		char ch;
		do
		{
			ch = getchar();
		} while (isspace(ch));
		while (!isspace(ch) && ch != EOF)
		{
			x.push_back(ch);
			ch = getchar();
		}
	}

	void _write(int x)
	{
		if (x < 0)
		{
			putchar('-');
			x = -x;
		}
		if (x >= 10)
			_write(x / 10);
		putchar(x % 10 + '0');
	}

	void _write(const char *s)
	{
		while (*s)
			putchar(*s++);
	}

public:
	IO()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}

	// 提供统一的 read 接口
	template <typename T>
	void read(T &x)
	{
		_read(x);
	}

	template <typename T, typename... Args>
	void read(T &x, Args &...args)
	{
		_read(x);
		read(args...);
	}

	template <typename T>
	void write(const T &x)
	{
		_write(x);
	}

	template <typename T, typename... Args>
	void write(const T &x, const Args &...args)
	{
		_write(x);
		write(args...);
	}

	void newline()
	{
		putchar('\n');
	}
} io;

const int N = 50;
int n, m, i, j, k, T, flg, a[N];
void dfs(int k, int s)
{
	if (k > n)
		if (!s)
			++flg;
	else
	{
		dfs(k + 1, s);
		dfs(k + 1, s ^ a[k]);
	}
}
signed main()
{

	T = 10;
	while (T--)
	{
		n = io.read();
		m = 0;
		for (i = 1; i <= n; ++i)
			a[i] = io.read(), m ^= a[i];
		if (!m)
			io.write("NO\n");
		else
		{
			flg = 0;
			dfs(1, 0);
			io.write(flg > 1 ? "NO\n" : "YES\n");
		}
	}
	return 0;
}
