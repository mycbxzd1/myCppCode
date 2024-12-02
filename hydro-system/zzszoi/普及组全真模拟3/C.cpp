#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<vector<int>> memo; // ����¼

// �Ϸ��Լ��
bool hefa(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) return false;
    }
    return true;
}

// �ݹ��������п��ܵ�����
int digui(int arr[], int index, int n, int total_bricks) {
    if (!hefa(arr, index)) return 0;
    if (total_bricks == 0) return 1;

    // ����Ѿ��������ǰ״̬��ֱ�ӷ��ؽ��
    if (memo[index][total_bricks] != -1)
        return memo[index][total_bricks];

    int ways = 0;
    for (int i = 1; i <= total_bricks; ++i) {
        arr[index] = i;
        ways += digui(arr, index + 1, n, total_bricks - i);
    }

    // ��¼��ǰ״̬�Ľ��
    memo[index][total_bricks] = ways;
    return ways;
}

int main() {
    int n;
    cin >> n;

    // ��ʼ������¼
    memo.assign(n + 1, vector<int>(n + 1, -1));

    int arr[600];
    int total_ways = digui(arr, 0, n, n);

    // ��ӡ���
    cout << total_ways - 1 << endl;

    return 0;
}

