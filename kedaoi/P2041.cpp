#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target, sum = 0;
    cin >> n >> target;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a.begin(), a.end());
    
    int mi = abs(sum - target);
    int closestSum = sum;
    
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum2 = a[i] + a[left] + a[right];
            int as = abs(sum2 - target);
            
            if (as < mi) {
                mi = as;
                closestSum = sum2;
            }
            
            if (sum2 < target) {
                ++left;
            } else if (sum2 > target) {
                --right;
            } else {
                cout << mi << " " << closestSum;
                return 0; // 找到精确值后可以直接退出
            }
        }
    }
    
    cout << mi << " " << closestSum;
    return 0;
}
