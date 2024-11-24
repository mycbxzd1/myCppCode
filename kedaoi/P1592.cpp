#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 10005, M = 200005;

int n, m, st, ed;
int d[N];
int head[N], ver[M], nxt[M], tot;
bool ok[N], erased[N];

void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x], head[x] = tot;
}

void dfs(int x) {
    ok[x] = true;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (ok[y]) continue;
        dfs(y);
    }
}

void bfs() {
    memset(d, 0x3f, sizeof(d));
    d[ed] = 0;
    queue<int> qu;
    qu.push(ed);
    while (qu.size()) {
        int x = qu.front(); qu.pop();
        if (x == st) { cout << d[x] << endl; return; }
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (!ok[y] || erased[y] || d[y] <= d[x] + 1) continue;
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
        cin>>x>>y;
        add(y,x);
        if (x - y) add(y, x);
    }

    cin >> st >> ed;
    dfs(ed);

    for (int i = 1; i <= n; i++) {
        if (ok[i]) continue;
        for (int j = head[i]; j; j = nxt[i]) {
            if (ver[j] != ed) erased[ver[j]] = true;
        }
    }
    bfs();
    return 0;
}
