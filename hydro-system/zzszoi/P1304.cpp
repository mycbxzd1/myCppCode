#include <bits/stdc++.h>
using namespace std;
const int N = 510, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
struct rec
{
    int x, y, lie;
};
char s[N][N];
rec st, ed;
int n, m, d[N][N][3];
queue<rec> q;
bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void st_ed()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] == 'O')
                ed = {i, j, 0}, s[i][j] = '.';
            else if (s[i][j] == 'X')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (valid(x, y) && s[x][y] == 'X')
                    {
                        st = {min(i, x), min(j, y), k < 2 ? 1 : 2};
                        s[i][j] = s[x][y] = '.';
                        break;
                    }
                }
                if (s[i][j] == 'X')
                    st = {i, j, 0};
            }
}
bool check(rec Next)
{
    if (!valid(Next.x, Next.y) || s[Next.x][Next.y] == '#')
        return 0;
    if (Next.lie == 0 && s[Next.x][Next.y] != '.')
        return 0;
    if (Next.lie == 1 && s[Next.x][Next.y + 1] == '#')
        return 0;
    if (Next.lie == 2 && s[Next.x + 1][Next.y] == '#')
        return 0;
    return 1;
}
const int Next_x[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}},
          Next_y[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}},
          Next_lie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};
int bfs()
{
    memset(d, -1, sizeof d);
    q = queue<rec>();
    d[st.x][st.y][st.lie] = 0;
    q.push(st);
    while (q.size())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            rec Next = {now.x + Next_x[now.lie][i], now.y + Next_y[now.lie][i], Next_lie[now.lie][i]};
            if (check(Next) && d[Next.x][Next.y][Next.lie] == -1)
            {
                d[Next.x][Next.y][Next.lie] = d[now.x][now.y][now.lie] + 1;
                q.push(Next);
                if (Next.x == ed.x && Next.y == ed.y && Next.lie == ed.lie)
                    return d[Next.x][Next.y][Next.lie];
            }
        }
    }
    return -1;
}
int main()
{
    while (cin >> n >> m && n && m)
    {
        for (int i = 1; i <= n; i++)
            cin >> s[i] + 1;
        st_ed();
        int ans = bfs();
        cout << (ans == -1 ? "Impossible" : to_string(ans)) << '\n';
    }
    return 0;
}
