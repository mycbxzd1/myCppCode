#include <iostream>
using namespace std;
const int mod = 1e9+7;
int n, dp[50010][13];
int countways() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100,200,500,1000,2000,5000,10000};
    for (int i = 0; i <= n; ++i)dp[i][0] = 1;
    for (int i = 1; i < 13; ++i)for (int j = 0; j <= n; ++j)for (int k = 0; k <= j / coins[i]; ++k) dp[j][i] = (dp[j][i] + dp[j - k * coins[i]][i - 1]) % mod;
    return dp[n][12];
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i)for (int j = 0; j < 7; ++j)dp[i][j] = 0;
    cout << (countways() % mod);
}

