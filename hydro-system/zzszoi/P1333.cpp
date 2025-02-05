#include <bits/stdc++.h>
using namespace std;
const int N = 510;
long double a[N][N], eps = 1e-8;
int c[N], n, m, dim, ans;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	int dim = 0;
	for (int i = 1; i <= m; i++)
	{
		int now = 0;
		for (int j = dim + 1; j <= n; j++)
			if (fabs(a[j][i]) > eps && (now == 0 || c[j] < c[now]))
				now = j;
		if (now == 0)
			continue;
		dim++;
		ans += c[now];
		for (int j = 1; j <= m; j++)
			swap(a[now][j], a[dim][j]);
		swap(c[now], c[dim]);
		for (int j = 1; j <= n; j++)
		{
			if (dim != j && fabs(a[j][i]) > eps)
			{
				long double rate = a[j][i] / a[dim][i];
				for (int k = i; k <= m; k++)
					a[j][k] -= a[dim][k] * rate;
			}
		}
	}
	cout << dim << " " << ans << endl;
}