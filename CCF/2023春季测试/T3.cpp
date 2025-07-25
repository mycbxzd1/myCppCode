#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;
struct Step {
    int left, right, turn;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    int peakIndex = 0;
    double maxY = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (y[i] > maxY) {
            maxY = y[i];
            peakIndex = i;
        }
    }
    x.insert(x.end(), x.begin(), x.end());
    y.insert(y.end(), y.begin(), y.end());
    vector dp(2*n,
               vector(2*n, vector<double>(2, INF)));
    vector prevStep(2*n,
                    vector(2*n, vector<Step>(2)));
    dp[peakIndex][peakIndex][0] = 0.0;
    dp[peakIndex + n][peakIndex + n][1] = 0.0;
    auto dist = [&](int i, int j) -> double {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx*dx + dy*dy);
    };
    for (int len = 2; len <= n; len++)
        for (int i = 0; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            double costA = dp[i+1][j][0] + dist(i, i+1);
            double costB = dp[i+1][j][1] + dist(i, j);
            if (costA <= costB) {
                dp[i][j][0] = costA;
                prevStep[i][j][0] = {i+1, j, 0};
            } else {
                dp[i][j][0] = costB;
                prevStep[i][j][0] = {i+1, j, 1};
            }
            double costC = dp[i][j-1][1] + dist(j-1, j);
            double costD = dp[i][j-1][0] + dist(i, j);
            if (costC <= costD) {
                dp[i][j][1] = costC;
                prevStep[i][j][1] = {i, j-1, 1};
            } else {
                dp[i][j][1] = costD;
                prevStep[i][j][1] = {i, j-1, 0};
            }
        }
    double bestCost = INF;
    int left = 0, right = 0, turn = 0;
    for (int i = 0; i + n - 1 < 2*n; i++) {
        int j = i + n - 1;
        if (dp[i][j][0] < bestCost) {
            bestCost = dp[i][j][0];
            left = i; right = j; turn = 0;
        }
        if (dp[i][j][1] < bestCost) {
            bestCost = dp[i][j][1];
            left = i; right = j; turn = 1;
        }
    }
    vector<int> order;
    int l = left, r = right, t = turn;
    for (int k = 0; k < n; k++) {
        int idx = (t == 0 ? l : r) % n;
        order.push_back(idx + 1);
        Step s = prevStep[l][r][t];
        l = s.left;
        r = s.right;
        t = s.turn;
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < n; i++)
        cout << order[i] << (i+1 < n ? ' ' : '\n');
    return 0;
}