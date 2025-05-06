#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class PathCounter
{
public:
    PathCounter(int rows, int cols, const vector<string> &grid)
        : rows(rows), cols(cols), grid(grid)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '.')
                {
                    endRow = i;
                    endCol = j;
                }
            }
        }
    }
    long long solve()
    {
        using CountMap = unordered_map<int, long long>;
        CountMap cur, next;
        cur.reserve(50000);
        next.reserve(50000);
        cur[0] = 1;
        long long result = 0;
        for (int i = 0; i < rows; ++i)
        {
            CountMap shifted;
            shifted.reserve(cur.size());
            for (auto &[state, cnt] : cur)
                shifted[state << 2] = cnt;
            cur.swap(shifted);
            for (int j = 0; j < cols; ++j)
            {
                next.clear();
                for (auto &[state, cnt] : cur)
                {
                    int left = (j > 0 ? getPlug(state, j - 1) : 0);
                    int up = getPlug(state, j);
                    if (grid[i][j] == '#')
                    {
                        if (!left && !up)
                            next[state] += cnt;
                        continue;
                    }
                    if (!left && !up)
                    {
                        if (canExtend(i, j + 1) && canExtend(i + 1, j))
                        {
                            int ns = state;
                            setPlug(ns, j - 1, 1);
                            setPlug(ns, j, 2);
                            next[ns] += cnt;
                        }
                    }
                    else if (!left && up)
                    {
                        if (canExtend(i, j + 1))
                            next[state] += cnt;
                        if (canExtend(i + 1, j))
                        {
                            int ns = state;
                            clearPlug(ns, j);
                            setPlug(ns, j - 1, up);
                            next[ns] += cnt;
                        }
                    }
                    else if (left && !up)
                    {
                        if (canExtend(i, j + 1))
                        {
                            int ns = state;
                            clearPlug(ns, j - 1);
                            setPlug(ns, j, left);
                            next[ns] += cnt;
                        }
                        if (canExtend(i + 1, j))
                            next[state] += cnt;
                    }
                    else if (left == 1 && up == 1)
                    {
                        int ns = state;
                        clearPlug(ns, j - 1);
                        clearPlug(ns, j);
                        int match = findMatching(ns, j + 1, 1, 2, +1);
                        clearPlug(ns, match);
                        next[ns] += cnt;
                    }
                    else if (left == 2 && up == 2)
                    {
                        int ns = state;
                        clearPlug(ns, j - 1);
                        clearPlug(ns, j);
                        int match = findMatching(ns, j - 2, 2, 1, -1);
                        setPlug(ns, match, 1);
                        next[ns] += cnt;
                    }
                    else if (left == 2 && up == 1)
                    {
                        int ns = state;
                        clearPlug(ns, j - 1);
                        clearPlug(ns, j);
                        next[ns] += cnt;
                    }
                    else if (i == endRow && j == endCol)
                        result += cnt;
                }
                cur.swap(next);
            }
        }
        return result;
    }

private:
    int rows, cols;
    int endRow = 0, endCol = 0;
    const vector<string> &grid;
    int getPlug(int state, int pos) const
    {
        return (state >> (2 * pos)) & 3;
    }
    void setPlug(int &state, int pos, int val) const
    {
        state |= (val << (2 * pos));
    }
    void clearPlug(int &state, int pos) const
    {
        state &= ~(3 << (2 * pos));
    }
    bool canExtend(int i, int j) const
    {
        return i < rows && j < cols && grid[i][j] == '.';
    }
    int findMatching(int state, int start, int openVal, int closeVal, int dir) const
    {
        int depth = 1;
        for (int k = start; k >= 0 && k < cols + 10; k += dir)
        {
            int v = getPlug(state, k);
            if (v == openVal)
                ++depth;
            else if (v == closeVal)
            {
                if (--depth == 0)
                    return k;
            }
        }
        return -1;
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    PathCounter solver(n, m, grid);
    cout << solver.solve() << "\n";
    return 0;
}
