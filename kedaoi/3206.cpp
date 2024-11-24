#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> parent, jiegou, parity;
int find(int u) {
    if (parent[u] != u) {
        int root = find(parent[u]);
        parity[u] ^= parity[parent[u]];
        parent[u] = root;
    }
    return parent[u];
}
bool unionSets(int u, int v, int p) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) {
        return (parity[u] ^ parity[v]) == p;
    }
    if (jiegou[pu] > jiegou[pv]) {
        swap(pu, pv);
    }
    
    parent[pu] = pv;
    parity[pu] = parity[u] ^ parity[v] ^ p;

    if (jiegou[pu] == jiegou[pv]) {
        jiegou[pv]++;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    jiegou.resize(n + 1, 0);
    parity.resize(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        string parityStr;
        cin >> l >> r >> parityStr;
        
        int p = (parityStr == "even") ? 0 : 1;

        if (!unionSets(l - 1, r, p)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << m << endl;
    return 0;
}
