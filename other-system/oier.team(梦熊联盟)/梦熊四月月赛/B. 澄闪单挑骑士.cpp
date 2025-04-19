#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

long long minCostToCoverCorridor(int n, int v[], int L) {
    const long long INF = 1e18;
    long long dp[MAX_N];
    fill(dp, dp + L + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1LL * v[j] * (j + 1) * (i - i + j) / 2);
            }
        }
    }

    return dp[L];
}

int main() {
    int n, L;
    cin >> n >> L;
    int v[MAX_N];
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    long long result = minCostToCoverCorridor(n, v, L);
    cout << result << endl;

    return 0;
}

