#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
enum class logic
{
    T,
    F,
    U
};
logic operator!(logic x)
{
    switch (x)
    {
    case logic::T:
        return logic::F;
    case logic::F:
        return logic::T;
    case logic::U:
        return logic::U;
    }
    return logic::U;
}
static vector<pair<int, int>> adj[N];
static int exprType[N], rootVar[N], flipPar[N], constVal[N];
static bool visited[N];
static int parityToRoot[N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            exprType[i] = 0;
            rootVar[i] = i;
            flipPar[i] = 0;
        }
        for (int k = 0; k < m; k++)
        {
            char op;
            cin >> op;
            if (op == 'T' || op == 'F' || op == 'U')
            {
                int i;
                cin >> i;
                exprType[i] = 1;
                if (op == 'T')
                    constVal[i] = 1;
                else if (op == 'F')
                    constVal[i] = 0;
                else
                    constVal[i] = 2;
            }
            else if (op == '+')
            {
                int i, j;
                cin >> i >> j;
                if (exprType[j] == 0)
                {
                    exprType[i] = 0;
                    rootVar[i] = rootVar[j];
                    flipPar[i] = flipPar[j];
                }
                else
                {
                    exprType[i] = 1;
                    constVal[i] = constVal[j];
                }
            }
            else if (op == '-')
            {
                int i, j;
                cin >> i >> j;
                if (exprType[j] == 0)
                {
                    exprType[i] = 0;
                    rootVar[i] = rootVar[j];
                    flipPar[i] = flipPar[j] ^ 1;
                }
                else
                {
                    exprType[i] = 1;
                    if (constVal[j] == 2)
                        constVal[i] = 2;
                    else
                        constVal[i] = 1 - constVal[j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= n; i++)
        {
            if (exprType[i] == 0)
            {
                int r = rootVar[i], f = flipPar[i];
                if (r == i && f == 1)
                {
                    exprType[i] = 1;
                    constVal[i] = 2;
                }
                else if (r != i)
                {
                    adj[i].emplace_back(r, f);
                    adj[r].emplace_back(i, f);
                }
            }
        }
        fill(visited + 1, visited + n + 1, false);
        long long answer = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            queue<int> q;
            vector<int> comp;
            bool needU = false;
            bool boolConflict = false;
            int forcedRootVal = -1;
            visited[i] = true;
            parityToRoot[i] = 0;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                if (exprType[u] == 1)
                {
                    int cv = constVal[u];
                    if (cv == 2)
                        needU = true;
                    else
                    {
                        int pr = parityToRoot[u];
                        int want = cv ^ pr;
                        if (forcedRootVal == -1)
                            forcedRootVal = want;
                        else if (forcedRootVal != want)
                            boolConflict = true;
                    }
                }
                for (auto &e : adj[u])
                {
                    int v = e.first, w = e.second;
                    if (!visited[v])
                    {
                        visited[v] = true;
                        parityToRoot[v] = parityToRoot[u] ^ w;
                        q.push(v);
                    }
                    else if (parityToRoot[v] != (parityToRoot[u] ^ w))
                        boolConflict = true;
                }
            }
            if (needU || boolConflict)
                answer += (int)comp.size();
        }
        cout << answer << "\n";
    }
    return 0;
}
