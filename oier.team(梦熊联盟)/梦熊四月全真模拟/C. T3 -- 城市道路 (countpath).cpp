#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int F(int x) {
    int count = 0;
    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
        dp[1][0] = 1;

        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                for (int k = 0; k < i - 1; ++k) {
                    if (F(A[i - 1] & A[k]) == j) {
                        dp[i][j] = (dp[i][j] + dp[k + 1][j - 1]) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for (int j = 0; j < N; ++j) {
            result = (result + dp[N][j]) % MOD;
        }

        cout <<dp[N][N] << endl;
    }

    return 0;
}

