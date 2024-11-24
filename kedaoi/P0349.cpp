#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int cost[N][N],parent[N];
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

// 合并两个集合
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    int n;cin >> n;
    node edges[N * N];
    int edgeCount = 0;
    // 读取输入矩阵并存储边
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
            if (i < j) { // 只存储上三角矩阵，避免重复
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }
    // 初始化并查集
    for (int i = 0; i < n; ++i)parent[i] = i;
    sort(edges, edges + edgeCount);
    int totalCost = 0;
    int edgesUsed = 0;
    // Kruskal算法
    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

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
