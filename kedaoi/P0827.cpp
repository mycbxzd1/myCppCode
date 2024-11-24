#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n, m, d[N];
int head[N], ver[N], nxt[N], tot;
void add(int x, int y) {
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void bfs() {
    queue<int> qu;
    qu.push(1);
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    while (qu.size()) {
        int x = qu.front(); qu.pop();
        if (x == n) { cout << d[x] << endl; return; }
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (d[y] <= d[x] + 1) continue;
            d[y] = d[x] + 1;
            qu.push(y);
        }
    }
    puts("-1");
}

int main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x != y) add(x, y); // 过滤自环
    }
    bfs();
    return 0;
}
