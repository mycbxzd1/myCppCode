#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<vector<int>> memo; // 备忘录

// 合法性检查
bool hefa(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) return false;
    }
    return true;
}

// 递归生成所有可能的排列
int digui(int arr[], int index, int n, int total_bricks) {
    if (!hefa(arr, index)) return 0;
    if (total_bricks == 0) return 1;

    // 如果已经计算过当前状态，直接返回结果
    if (memo[index][total_bricks] != -1)
        return memo[index][total_bricks];

    int ways = 0;
    for (int i = 1; i <= total_bricks; ++i) {
        arr[index] = i;
        ways += digui(arr, index + 1, n, total_bricks - i);
    }

    // 记录当前状态的结果
    memo[index][total_bricks] = ways;
    return ways;
}

int main() {
    int n;
    cin >> n;

    // 初始化备忘录
    memo.assign(n + 1, vector<int>(n + 1, -1));

    int arr[600];
    int total_ways = digui(arr, 0, n, n);

    // 打印结果
    cout << total_ways - 1 << endl;

    return 0;
}

