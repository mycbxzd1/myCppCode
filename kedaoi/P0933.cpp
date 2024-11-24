#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n, m, d[N];
int head[N], ver[N], nxt[N], tot;
void add(int x, int y) {
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void dfs(int x) {
    for(int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if(d[y] >= d[x]) continue;
        d[y] = d[x];
        dfs(y);
    }
}
int main() {
    cin >> n >> m;
    while(m--) {
        int x, y;
        cin>>x>>y;
        add(y, x);
    }
    for(int i = n; i >= 1; i--) {
        d[i] = max(i, d[i]);
        dfs(i);
    }
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
}