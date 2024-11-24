/*
 * 不考虑路径压缩
 * fa[x]表示x前面的那艘战舰的编号
 * 我们让每条边带上1单位的权值，这样树上的两点之间的距离-1就是二者之间战舰的数量
 *
 * 考虑路径压缩
 * 额外建立一个sz[]数组，sz[x]记录战舰x到fa[x]之间的边权值
 * 在路径压缩把x(摘下来)直接指向树根的同时，我们把sz[x]更新为
 * 从x到树根的路径上的所有边权之和
 */
// d[x]记录x前面有多少艘战舰，路径压缩的过程中已经正确处理了d[]值，因此在每个节点都有效
// sz[find(x)]记录x所在的这一列的战舰数，因为有路径压缩的存在，sz[]只在根节点有效
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30005, INF = 0x3f3f3f3f;
int fa[N], d[N], sz[N];

int find(int x) {
    if (fa[x] == x) return x;
    int root = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y, d[x] = sz[y];
    sz[y] += sz[x];
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= 30000; i++) fa[i] = i, d[i] = 0, sz[i] = 1;
    char op[2]; int x, y;
    while (T--) {
        scanf("%s%d%d", op, &x, &y);
        int rx = find(x), ry = find(y);
        if (op[0] == 'M' && rx != ry) {
            fa[rx] = ry; d[rx] = sz[ry];
            sz[ry] += sz[rx];
        } else {
            if (rx == ry) cout << (x == y ? 0 : abs(d[x] - d[y]) - 1) << endl;
            else puts("-1");
        }
    }
    return 0;
}
