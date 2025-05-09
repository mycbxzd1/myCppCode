#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Edge
{
    int v, next;
} edge[N << 1];
int head[N], cnt;
inline void add_edge(int u, int v)
{
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}
inline long long read()
{
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(long long x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
long long a[N];
int b[N], c[N];
__int128 ddl[N];
inline __int128 high(int u, __int128 x)
{
    if (c[u] >= 0)
        return b[u] * x + x * (x + 1) / 2 * c[u];
    else
    {
        if (x <= ddl[u])
            return b[u] * x + x * (x + 1) / 2 * c[u];
        else
            return b[u] * ddl[u] + ddl[u] * (ddl[u] + 1) / 2 * c[u] + (x - ddl[u]);
    }
}
inline bool enough(int u, __int128 x, __int128 target)
{
    if (c[u] >= 0)
        return b[u] * x + x * (x + 1) / 2 * c[u] <= target;
    else
    {
        if (x <= ddl[u])
            return b[u] * x + x * (x + 1) / 2 * c[u] <= target;
        else
            return b[u] * ddl[u] + ddl[u] * (ddl[u] + 1) / 2 * c[u] + (x - ddl[u]) <= target;
    }
}
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
int n, r[N], s[N];
void dfs(int u, int fa)
{
    for (int i = head[u], v; i; i = edge[i].next)
    {
        v = edge[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        r[u] = min(r[u], r[v]);
    }
}

bool check(int x)
{
    if (x < n)
        return false;
    for (int u = 1; u <= n; u++)
    {
        __int128 tgt = high(u, x) - a[u];
        if (tgt < 0)
            return false;
        r[u] = 1;
        for (int i = 29; i >= 0; i--)
        {
            int nx = r[u] + (1 << i);
            if (nx <= x && enough(u, nx - 1, tgt))
                r[u] = nx;
        }
    }
    dfs(1, 0);
    memset(s + 1, 0, n * sizeof(int));
    for (int u = 1; u <= n; u++)
    {
        if (r[u] < 1)
            return false;
        s[min(r[u], n)]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += s[i];
        if (sum > i)
            return false;
    }
    return true;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = read();
        c[i] = read();
        if (c[i] < 0)
            ddl[i] = (b[i] - 1) / (-c[i]);
    }
    for (int i = 1, u, v; i < n; i++)
    {
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    int ans = (1 << 30) - 1;
    for (int i = 29; i >= 0; i--)
        if (check(ans ^ (1 << i)))
            ans ^= (1 << i);
    write(ans);
    return 0;
}
