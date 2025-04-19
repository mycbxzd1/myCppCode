#include <iostream>
#include <algorithm>
using namespace std;
int a[20010];
int min_difference(int candies[], int n) {
    if (n == 0) return 0;
    sort(candies, candies + n);
    int left = 0, right = n - 1;
    int sum_w = 0, sum_z = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sum_w += candies[left++];
        } else {
            sum_z += candies[right--];
        }
	}
    return abs(sum_w - sum_z);
}
int main() {
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
    int min_diff = min_difference(a, n);
    cout<< min_diff << endl;

    return 0;
}

