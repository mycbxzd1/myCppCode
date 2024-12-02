#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sequence[100]; // �������100��Ԫ�أ�����ʵ�����������С
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // �ҳ����� [l, r]
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

