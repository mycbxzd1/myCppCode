#include<bits/stdc++.h> 
using namespace std;
const int N = 110;
bool dp[N + 1][N * 100 + 1] = {false};//��ʾǰi�������ܷ�ȡ��ʹ�����ǵĺ�Ϊj������ 
int num[110],sum;
int main() {
    int n;cin>>n;
    for (int i = 0; i < n; ++i)cin >> num[i],sum += num[i];
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)for (int j = 0; j <= sum / 2; ++j)(j >= num[i - 1])?dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - num[i - 1]]):(dp[i][j] = dp[i - 1][j]);
    int _sum = sum / 2;
    while (!dp[n][_sum])_sum--;
    int sum_1 = sum - _sum;
	cout<<abs(_sum - sum_1);
}
