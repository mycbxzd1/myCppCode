#include <iostream>
#include <algorithm>
using namespace std;

// 检查是否可以在最大救火时间为 max_time 的条件下分配 k 只猫
bool check(int n, int k, int max_time) {
    int cnt = 1;  // 第一只猫分配在第一个仓库
    int last_pos = 1;  // 第一个仓库的编号是 1

    for (int i = 2; i <= n; i++) {  // 仓库编号从 1 到 n
        if (i - last_pos > max_time) {
            cnt++;  // 放一只新的猫
            last_pos = i;  // 更新上一次放猫的位置
        }
        if (cnt > k) return false;  // 剪枝：如果猫的数量超过 k，直接返回 false
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    // 二分查找最小的最大救火时间
    int l = 0, r = n - 1, ans = r;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(n, k, mid)) {
            ans = mid;  // 可以满足条件，尝试缩小范围
            r = mid - 1;
        } else {
            l = mid + 1;  // 不满足条件，扩大范围
        }
    }

    // 输出 k 个仓库编号，分配方式可以是任意合法分配
    int last_pos = 1;
    cout << last_pos << endl;
    for (int i = 2, cnt = 1; cnt < k && i <= n; i++) {
        if (i - last_pos > ans) {
            cout << i << endl;
            last_pos = i;
            cnt++;
        }
    }

    return 0;
}

