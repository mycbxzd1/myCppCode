#include <iostream>
using namespace std;
int path[25];
void dfs(int n, int start, int path[], int now) {
    if (n == 0) {
        for (int i = 0; i < now; ++i) {
            if (i > 0) cout << " + ";
            cout << path[i];
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        path[now] = i;
        dfs(n - i, i, path, now + 1);
    }
}
int main() {
    int n;cin >> n;
    dfs(n, 1, path, 0);
    return 0;
}
