#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000; // 假设最大输入大小为1000000

int main() {
    int n, m;
    cin >> n >> m;
    int a[N];
    for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a, a + n); // 排序
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == m) {
            cout << a[l] << " " << a[r] << endl;
            ++l;
        } else if (sum < m) {
            ++l;
        } else {
            --r;
        }
    }
    return 0;
}
