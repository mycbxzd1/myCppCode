#include <bits/stdc++.h>
using namespace std;
const int N = 506, INF = 0x3f3f3f3f;
int r, c, d[N][N];
char s[N][N];
vector<tuple<int, int, int>> p[N][N];
deque<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            cin >> (s[i] + 1);
        if ((r ^ c) & 1)
        {
            cout << "NO SOLUTION\n";
            continue;
        }
        for (int i = 0; i <= r; i++)
            for (int j = 0; j <= c; j++)
                p[i][j].clear();
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++)
            {
                int w = (s[i][j] == '/');
                p[i - 1][j - 1].push_back({i, j, w});
                p[i][j].push_back({i - 1, j - 1, w});
                p[i][j - 1].push_back({i - 1, j, !w});
                p[i - 1][j].push_back({i, j - 1, !w});
            }
        }
        memset(d, INF, sizeof(d));
        d[0][0] = 0;
        q.push_back({0, 0});
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop_front();
            if (x == r && y == c)
            {
                cout << d[r][c] << '\n';
                break;
            }
            for (auto [nx, ny, w] : p[x][y])
            {
                if (d[nx][ny] > d[x][y] + w)
                {
                    d[nx][ny] = d[x][y] + w;
                    w ? q.push_back({nx, ny}) : q.push_front({nx, ny});
                }
            }
        }
    }
}
