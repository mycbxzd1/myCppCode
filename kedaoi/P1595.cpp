#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int n, m, a, b;
bool visited[N];
vector<int> g[N];

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int y = g[u][i];
        if (!visited[y]) {
            dfs(y);
        }
    }
}

int main() {
    cin >> a >> b;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    // 从泪城节点（节点1）出发，检查是否能到达大黄蜂所在的节点a
    memset(visited, 0, sizeof(visited));
    dfs(1);

    if (!visited[a]) {
        cout << "no" << endl;
        return 0;
    }

    // 从大黄蜂所在的节点a出发，检查是否能到达王后花园节点b
    memset(visited, 0, sizeof(visited));
    dfs(a);

    cout << (visited[b] ? "fenda" : "no") << endl;
    return 0;
}
