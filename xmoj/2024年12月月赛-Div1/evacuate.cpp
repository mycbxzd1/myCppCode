#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    vector<int> parent,rank;
    Node(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
signed main() {
    freopen("evacuate.in","r",stdin);
    freopen("evacuate.out","w",stdout);
    int N, M, Q;cin >> N >> M >> Q;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }
    vector<int> C(Q), D(Q);
    for (int i = 0; i < Q; i++) {
        cin >> C[i] >> D[i];
        C[i]--;D[i]--;
    }
    set<pair<int,int>> st;
    for (int i = 0; i < Q; i++)st.insert({C[i], D[i]});
    vector<bool> not_broken(M, false);
    for (int i = 0; i < M; i++)if (st.find({A[i], B[i]})==st.end())not_broken[i] = true;
    vector<int> now_ok(N, -1), now_ng(N, Q + 1);
    for (int i = 0; i < 20; i++) {
        vector<vector<int>> mid_idx(Q + 1);
        for (int j = 0; j < N; j++) {
            int mid = (now_ng[j] + now_ok[j]) / 2;
            if (mid >= 0 && mid <= Q)mid_idx[mid].push_back(j);
        }
        Node tree(N);
        for (int j = 0; j < M; j++)if (not_broken[j])tree.merge(A[j], B[j]);
        for (int j : mid_idx[Q]) {
            if (tree.same(0, j))now_ok[j] = Q;
            else now_ng[j] = Q;
        }
        for (int j = Q - 1; j >= 0; j--) {
            tree.merge(C[j], D[j]);
            for (int k : mid_idx[j]) {
                if (tree.same(0, k))now_ok[k] = j;
                else now_ng[k] = j;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (now_ng[i] == Q + 1)cout << -1 << endl;
        else cout << now_ng[i] << endl;
    }
    return 0;
}
