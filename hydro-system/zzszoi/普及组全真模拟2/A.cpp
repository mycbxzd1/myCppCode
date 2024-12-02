#include <iostream>
#include <vector>
using namespace std;
int find(int x, vector<int> &parent);

int main() {
    int a, b, p;
    cin >> a >> b >> p;

    int ans = b - a + 1; // 将答案初始化为 a~b 间数的个数，每合并一次减 1

    vector<int> parent(b + 1); // 使用 vector 存储 parent 数组
    vector<bool> is_prime(b + 1, true); // 使用 vector 存储 is_prime 数组

    // 初始化 parent 数组
    for (int i = a; i <= b; ++i) {
        parent[i] = i;
    }

    // 埃氏筛
    for (int i = 2; i <= b; ++i) {
        if (!is_prime[i])
            continue;

        if (i >= p) { // 如果当前质数大于等于 p 才合并
            for (int j = i * 2; j <= b; j += i) {
                is_prime[j] = false;
                if (j - i >= a) {
                    int root_j = find(j, parent);
                    int root_j_minus_i = find(j - i, parent);
                    if (root_j != root_j_minus_i) {
                        parent[root_j] = root_j_minus_i;
                        --ans;
                    }
                }
            }
        } else {
            for (int j = i * 2; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }

    cout << ans;

    return 0;
}

int find(int x, vector<int> &parent) {
    return x == parent[x] ? x : parent[x] = find(parent[x], parent);
}

