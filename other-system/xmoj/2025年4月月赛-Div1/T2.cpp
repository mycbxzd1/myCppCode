#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int N, M;
vector<int> g[MAXN];
bool vis[MAXN], adj1[MAXN], found = false;
void dfs(int u, int depth)
{
    if (found)
        return;
    if (depth == 4)
    {
        if (adj1[u])
            found = true;
        return;
    }
    for (int v : g[u])
    {
        if (v == 1 || vis[v])
            continue;
        vis[v] = true;
        dfs(v, depth + 1);
        vis[v] = false;
        if (found)
            return;
    }
}

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    for (int v : g[1])
        adj1[v] = true;
    vis[1] = true;
    dfs(1, 0);
    cout << (found ? "YES" : "NO") << "\n";
    return 0;
}
