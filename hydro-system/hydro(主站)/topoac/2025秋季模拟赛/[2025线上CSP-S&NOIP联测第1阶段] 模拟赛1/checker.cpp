#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    Edge(int u = 0, int v = 0) : u(u), v(v) {}
};

class NetworkChecker {
private:
    int n, m, k;
    vector<Edge> original_edges;
    set<int> suspicious;
    
    // 选手答案
    int central_station;
    vector<Edge> selected_edges;
    
    // 构建的树
    vector<vector<int>> tree;
    
public:
    bool readInput(const string& input_file) {
        ifstream fin(input_file);
        if (!fin) return false;
        
        fin >> n >> m;
        original_edges.resize(m);
        
        for (int i = 0; i < m; i++) {
            fin >> original_edges[i].u >> original_edges[i].v;
        }
        
        fin >> k;
        for (int i = 0; i < k; i++) {
            int a;
            fin >> a;
            suspicious.insert(a);
        }
        
        fin.close();
        return true;
    }
    
    bool readContestantOutput(const string& output_file) {
        ifstream fout(output_file);
        if (!fout) return false;
        
        string result;
        fout >> result;
        
        if (result == "NO") {
            fout.close();
            return true; // NO答案需要特殊处理
        }
        
        if (result != "YES") return false;
        
        fout >> central_station;
        if (central_station < 1 || central_station > n) return false;
        
        selected_edges.resize(n - 1);
        for (int i = 0; i < n - 1; i++) {
            fout >> selected_edges[i].u >> selected_edges[i].v;
            if (selected_edges[i].u < 1 || selected_edges[i].u > n ||
                selected_edges[i].v < 1 || selected_edges[i].v > n ||
                selected_edges[i].u == selected_edges[i].v) {
                return false;
            }
        }
        
        fout.close();
        return true;
    }
    
    bool isValidEdgeSet() {
        // 检查选手输出的边是否都在原始边集中
        set<pair<int, int>> original_set;
        for (const auto& e : original_edges) {
            original_set.insert({min(e.u, e.v), max(e.u, e.v)});
        }
        
        for (const auto& e : selected_edges) {
            pair<int, int> edge = {min(e.u, e.v), max(e.u, e.v)};
            if (original_set.find(edge) == original_set.end()) {
                return false;
            }
        }
        return true;
    }
    
    bool buildTree() {
        tree.assign(n + 1, vector<int>());
        
        for (const auto& e : selected_edges) {
            tree[e.u].push_back(e.v);
            tree[e.v].push_back(e.u);
        }
        
        // 检查是否为树（连通且n-1条边）
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int count = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : tree[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count == n;
    }
    
    vector<int> getPath(int start, int end) {
        if (start == end) return {start};
        
        vector<int> parent(n + 1, -1);
        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (u == end) break;
            
            for (int v : tree[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        if (!visited[end]) return {}; // 无路径
        
        vector<int> path;
        int cur = end;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    bool checkConstraint() {
        // 检查从中央站到每个其他站的路径是否最多经过1个可疑站
        for (int i = 1; i <= n; i++) {
            if (i == central_station) continue;
            
            vector<int> path = getPath(central_station, i);
            if (path.empty()) return false;
            
            int suspicious_count = 0;
            for (int station : path) {
                if (suspicious.find(station) != suspicious.end()) {
                    suspicious_count++;
                }
            }
            
            if (suspicious_count > 1) {
                return false;
            }
        }
        return true;
    }
    
    bool checkSolution() {
        // 检查边集是否有效
        if (!isValidEdgeSet()) {
            return false;
        }
        
        // 构建树并检查连通性
        if (!buildTree()) {
            return false;
        }
        
        // 检查约束条件
        if (!checkConstraint()) {
            return false;
        }
        
        return true;
    }
    
    bool isNoAnswer(const string& contestant_output) {
        ifstream fout(contestant_output);
        if (!fout) return false;
        
        string result;
        fout >> result;
        fout.close();
        
        return result == "NO";
    }
    
    // 简单的可行性检查（用于验证NO答案）
    bool hasPossibleSolution() {
        // 如果可疑站点过多，可能无解
        // 这里实现一个简化的检查
        if (k > n - 1) return false;
        
        // 构建原图并检查连通性
        vector<vector<int>> graph(n + 1);
        for (const auto& e : original_edges) {
            graph[e.u].push_back(e.v);
            graph[e.v].push_back(e.u);
        }
        
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int count = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count == n;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <input_file> <standard_output> <contestant_output>" << endl;
        return 1;
    }
    
    string input_file = argv[1];
    string standard_output = argv[2];   // 标准答案文件
    string contestant_output = argv[3]; // 选手答案文件
    
    NetworkChecker checker;
    
    if (!checker.readInput(input_file)) {
        cout << "WA" << endl;
        return 0;
    }
    
    // 检查选手输出是否是NO
    if (checker.isNoAnswer(contestant_output)) {
        // 如果选手答案是NO，需要验证标准答案是否也是NO
        // 或者验证确实无解（这里简化处理）
        if (checker.isNoAnswer(standard_output)) {
            cout << "AC" << endl;
        } else {
            // 标准答案有解但选手说无解，需要更仔细的验证
            // 这里简化为WA，实际应该验证是否真的有解
            cout << "WA" << endl;
        }
        return 0;
    }
    
    // 选手给出了YES答案，验证其正确性
    if (!checker.readContestantOutput(contestant_output)) {
        cout << "WA" << endl;
        return 0;
    }
    
    if (checker.checkSolution()) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    
    return 0;
}