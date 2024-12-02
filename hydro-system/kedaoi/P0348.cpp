#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int cost[N][N], parent[N];

struct node {
    int u, v, weight;
    bool operator<(const node& other) const {
        return weight < other.weight;
    }
};

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    int n;
    cin >> n;
    vector<node> edges;
    
    // 读取输入矩阵并存储边
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
            if (i < j) {
                edges.push_back({i, j, cost[i][j]});
            }
        }
    }
    
    // 初始化并查集
    for (int i = 0; i < n; ++i) parent[i] = i;
    
    sort(edges.begin(), edges.end());
    
    int totalCost = 0;
    int edgesUsed = 0;
    
    // Kruskal算法
    for (const auto& e : edges) {
        int u = e.u;
        int v = e.v;
        int weight = e.weight;

        if (find(u) != find(v)) {
            unite(u, v);
            totalCost += weight;
            edgesUsed++;
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }
    
    cout << totalCost << endl;
    return 0;
}
