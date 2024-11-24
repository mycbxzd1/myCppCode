#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sequence[100]; // 假设最多100个元素，根据实际情况调整大小
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // 找出区间 [l, r]
    int max_count = 0;
    for (int l = 0; l < n; ++l) {
        map<int, int> count;
        int r = l;
        while (r < n && sequence[r] == sequence[l]) {
            count[sequence[r]]++;
            r++;
        }
        for (int i = l; i < r; ++i) {
            sequence[i] += k;
        }
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
            if (it->second > max_count) {
                max_count = it->second;
            }
        }
    }

    cout << max_count << endl;

    return 0;
}

