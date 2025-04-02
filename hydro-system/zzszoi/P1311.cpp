#include<bits/stdc++.h>
using namespace std;
struct State {
    int board, cost;
    bool operator<(const State &other) const {
        return cost > other.cost;
    }
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int target = 0;
    for (int i = 1; i <= 8; ++i)
        target = target * 9 + i;
    target = target * 9;
    int board[3][3];
    int emptyX = 0, emptyY = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            string s;
            cin >> s;
            if (s == "x") {
                board[i][j] = 0;
                emptyX = i;
                emptyY = j;
            } else {
                board[i][j] = stoi(s);
            }
        }
    }
    int invCount = 0;
    int arr[9], idx = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arr[idx++] = board[i][j];
    for (int i = 0; i < 9; ++i) {
        if (arr[i] == 0) continue;
        for (int j = i + 1; j < 9; ++j) {
            if (arr[j] == 0) continue;
            if (arr[i] > arr[j])
                ++invCount;
        }
    }
    if (invCount & 1) {
        cout << "unsolvable";
        return 0;
    }
    auto boardToInt = [&]() -> int {
        int state = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                state = state * 9 + board[i][j];
        return state;
    };
    auto heuristic = [&](int state) -> int {
        int h = 0;
        int temp = state;
        int b[3][3];
        for (int i = 2; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                b[i][j] = temp % 9;
                temp /= 9;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = b[i][j];
                if (num == 0)
                    continue;
                int targetX = (num - 1) / 3;
                int targetY = (num - 1) % 3;
                h += abs(i - targetX) + abs(j - targetY);
            }
        }
        return h;
    };
    auto intToBoard = [&](int state, int b[3][3], int &ex, int &ey) {
        int temp = state;
        for (int i = 2; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                b[i][j] = temp % 9;
                if (b[i][j] == 0) {
                    ex = i;
                    ey = j;
                }
                temp /= 9;
            }
        }
    };

    int startState = boardToInt();
    map<int, int> dist;
    map<int, int> parent;
    map<int, int> moveDir;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    char dirChar[4] = {'u', 'l', 'r', 'd'};
    priority_queue<State> pq;
    dist[startState] = 0;
    pq.push({startState, heuristic(startState)});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        int curState = current.board;
        if (current.cost != dist[curState] + heuristic(curState))
            continue;
        if (curState == target)
            break;
        int currentG = dist[curState];
        int curBoard[3][3], ex, ey;
        intToBoard(curState, curBoard, ex, ey);
        for (int i = 0; i < 4; ++i) {
            int nx = ex + dx[i], ny = ey + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            swap(curBoard[ex][ey], curBoard[nx][ny]);
            int nextState = 0;
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c)
                    nextState = nextState * 9 + curBoard[r][c];
            if (!dist.count(nextState) || dist[nextState] > currentG + 1) {
                dist[nextState] = currentG + 1;
                parent[nextState] = curState;
                moveDir[nextState] = i;
                pq.push({nextState, dist[nextState] + heuristic(nextState)});
            }
            swap(curBoard[ex][ey], curBoard[nx][ny]);
        }
    }

    if (!dist.count(target))
        cout << "unsolvable";
    else {
        string path;
        int state = target;
        while (state != startState) {
            path.push_back(dirChar[moveDir[state]]);
            state = parent[state];
        }
        reverse(path.begin(), path.end());
        cout << path;
    }
    return 0;
}