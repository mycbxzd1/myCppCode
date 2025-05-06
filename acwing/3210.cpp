#include <bits/stdc++.h>
using namespace std;

const int N = 600, M = 107, INF = 0x3f3f3f3f;

int n, m;
int g[110][10], q[2][N], cnt[2];
int h[2][M], v[2][M];

inline int max2(int x, int y) {
    return x > y ? x : y;
}

inline int encode(int k, int val) {
    return val << (k * 2);
}

int find_idx(int cur, int x) {
    int t = x % M;
    while (h[cur][t] != -1 && h[cur][t] != x) {
        if (++t == M) t = 0;
    }
    return t;
}

inline int get(int state, int k) {
    return (state >> (k * 2)) & 3;
}

void insert_state(int cur, int state, int w) {
    int t = find_idx(cur, state);
    if (h[cur][t] == -1) {
        h[cur][t] = state;
        v[cur][t] = w;
        q[cur][++cnt[cur]] = t;
    } else {
        v[cur][t] = max2(v[cur][t], w);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    int res = -INF;
    memset(h, -1, sizeof h);
    int cur = 0;

    insert_state(cur, 0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cnt[cur]; j++)
            h[cur][q[cur][j]] <<= 2;
        for (int j = 1; j <= m; j++) {
            int last = cur;
            cur ^= 1;
            cnt[cur] = 0;
            memset(h[cur], -1, sizeof h[cur]);
            for (int k = 1; k <= cnt[last]; k++) {
                int state = h[last][q[last][k]];
                int w     = v[last][q[last][k]];
                int x = get(state, j - 1), y = get(state, j);

                if (!x && !y) {
                    insert_state(cur, state, w);
                    if (i < n && j < m)
                        insert_state(cur,
                                     state + encode(j - 1, 1) + encode(j, 2),
                                     w + g[i][j]);
                }
                else if (!x && y) {
                    if (i < n)
                        insert_state(cur,
                                     state - encode(j, y) + encode(j - 1, y),
                                     w + g[i][j]);
                    if (j < m)
                        insert_state(cur, state, w + g[i][j]);
                }
                else if (x && !y) {
                    if (i < n)
                        insert_state(cur, state, w + g[i][j]);
                    if (j < m)
                        insert_state(cur,
                                     state - encode(j - 1, x) + encode(j, x),
                                     w + g[i][j]);
                }
                else if (x == 1 && y == 1) {
                    for (int u = j + 1, s = 1;; u++) {
                        int z = get(state, u);
                        if (z == 1)      s++;
                        else if (z == 2) {
                            if (--s == 0) {
                                insert_state(cur,
                                             state - encode(j - 1, x)
                                                   - encode(j, y)
                                                   - encode(u, 1),
                                             w + g[i][j]);
                                break;
                            }
                        }
                    }
                }
                else if (x == 2 && y == 2) {
                    for (int u = j - 2, s = 1;; u--) {
                        int z = get(state, u);
                        if (z == 2)      s++;
                        else if (z == 1) {
                            if (--s == 0) {
                                insert_state(cur,
                                             state - encode(j - 1, x)
                                                   - encode(j, y)
                                                   + encode(u, 1),
                                             w + g[i][j]);
                                break;
                            }
                        }
                    }
                }
                else if (x == 2 && y == 1) {
                    insert_state(cur,
                                 state - encode(j - 1, x) - encode(j, y),
                                 w + g[i][j]);
                }
                else {
                    if (state == encode(j - 1, x) + encode(j, y))
                        res = max2(res, w + g[i][j]);
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}
