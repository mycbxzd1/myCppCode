#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int mp[N][N];
int dp[N] ;
int arr[N];
int ans[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];
	}
	for (int i = 2; i <= n; i++)dp[i] = N;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mp[j][i] != 0)
			{
				if (dp[i] > dp[j] + mp[j][i])
				{
					dp[i] = dp[j] + mp[j][i];
					arr[i] = j;
				}
			}
		}
	}
	cout <<"minlong="<< dp[n] << endl;
	int k = n,t=1;
	while (k >= 1)
	{
		ans[t++] = k;
		k = arr[k];
	}
	for (int i = t-1; i >=1 ; i--)cout << ans[i] << " ";
	return 0;
}
