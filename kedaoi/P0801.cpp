#include <iostream>
using namespace std;
int a[25],n;
void dfs(int n, int start, int now) {
    if (n == 0) {
        for (int i = 0; i < now; ++i) {
            if (i > 0) cout << " + ";
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; ++i) {
        a[now] = i;
        dfs(n - i, i, now + 1);
    }
}
int main() {
    cin >> n;
    dfs(n, 1, 0);
    return 0;
}
