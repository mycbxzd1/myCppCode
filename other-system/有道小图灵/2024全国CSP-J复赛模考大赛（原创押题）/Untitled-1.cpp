#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

const double EPS = 1e-6;

double calc(double a, double b, int op) {
    switch (op) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return b - a;
        case 3: return a * b;
        case 4: return b != 0 ? a / b : 1e9;
        case 5: return a != 0 ? b / a : 1e9;
        default: return 1e9;
    }
}

int bfs(vector<double>& nums) {
    queue<pair<vector<double>, int>> q;
    set<vector<double>> vis;
    sort(nums.begin(), nums.end());
    q.push({nums, 0});
    while (!q.empty()) {
        auto [cur, steps] = q.front();
        q.pop();
        if (cur.size() == 1 && fabs(cur[0] - 24) < EPS) return steps;

        int n = cur.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    vector<double> nxt;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) nxt.push_back(cur[k]);
                    }
                    for (int op = 0; op < 6; ++op) {
                        double res = calc(cur[i], cur[j], op);
                        if (res == 1e9) continue;
                        nxt.push_back(res);
                        sort(nxt.begin(), nxt.end());
                        if (vis.find(nxt) == vis.end()) {
                            vis.insert(nxt);
                            q.push({nxt, steps + 1});
                        }
                        nxt.pop_back();
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<double> nums(4);
        for (int i = 0; i < 4; ++i) cin >> nums[i];
        cout << bfs(nums) << endl;
    }
    return 0;
}
