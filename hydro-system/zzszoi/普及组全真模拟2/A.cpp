#include <iostream>
#include <vector>
using namespace std;
int find(int x, vector<int> &parent);

int main() {
    int a, b, p;
    cin >> a >> b >> p;

    int ans = b - a + 1; // ���𰸳�ʼ��Ϊ a~b �����ĸ�����ÿ�ϲ�һ�μ� 1

    vector<int> parent(b + 1); // ʹ�� vector �洢 parent ����
    vector<bool> is_prime(b + 1, true); // ʹ�� vector �洢 is_prime ����

    // ��ʼ�� parent ����
    for (int i = a; i <= b; ++i) {
        parent[i] = i;
    }

    // ����ɸ
    for (int i = 2; i <= b; ++i) {
        if (!is_prime[i])
            continue;

        if (i >= p) { // �����ǰ�������ڵ��� p �źϲ�
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

