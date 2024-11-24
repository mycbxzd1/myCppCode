#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    if (n < 2) {
        cout<<0<<endl;
        return 0;
    }
    vector<int> dp(n, 0);
    int max_len = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            if (i - 2 >= 0 && nums[i] != nums[i - 2]) dp[i] = dp[i - 2] + 2;
            else dp[i] = 2;
        }
        max_len = max(max_len, dp[i]);
    }
    cout<<max_len<<endl;
    return 0;
}

