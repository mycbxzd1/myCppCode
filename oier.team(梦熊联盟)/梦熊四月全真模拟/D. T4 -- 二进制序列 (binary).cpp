#include <bits/stdc++.h> 
using namespace std;
int A[1010][1010];
int main() {
    int W, H, C;
    cin >> W >> H >> C;
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            cin >> A[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            for (int k = i; k <= W; k++) {
                for (int l = j; l <= H; l++) {
                    if (i == k && j == l) continue;
                    ans = min(ans, A[i][j] + A[k][l] + C * (abs(i - k) + abs(j - l)));
                }
            }
        }
    }
    cout << ans ;
    return 0;
}

