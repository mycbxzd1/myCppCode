#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int t, l, r, w[N], g[N], vis[N], sz[N], is_prime[N], fa[N];
class Node {
public:
    int x, y, w;
    Node(int X=0, int Y=0, int W=0) : x(X), y(Y), w(W) {}
    bool operator<(const Node& other) const {return w < other.w;}
};
void init(int n) {
    for(int i=1; i<=n; ++i) g[i] = 1;
    for(int i=2; i<=n; ++i) {
        if(!w[i]) {
            is_prime[i] = 1;
            g[i] = i;
            w[i] = 1;
            for(int j=i*2; j<=n; j+=i) {
                ++w[j];
                g[j] *= i;
            }
        }
    }
}
int getfa(int x) {
    return fa[x] != x ? fa[x] = getfa(fa[x]) : x;
}
signed main() {
    cin >> t;
    init(1e6);
    while(t--) {
        cin >> l >> r;
        int ans = 0;
        if(l == 1) {
            for(int i=2; i<=r; ++i) ans += w[i];
            cout << ans << endl;
            continue;
        }
        bool has_prime = false;
        for(int i=l; i<=r; ++i) {
            if(is_prime[i]) {
                has_prime = true;
                break;
            }
        }
        if(has_prime) {
            fill(sz, sz + r + 1, 0);
            fill(vis, vis + r + 1, 0);
            for(int i=l; i<=r; ++i) ++sz[g[i]];
            for(int i=2; i<=r; ++i) {
                if(!vis[i] && sz[i]) {
                    ans += w[i] * (sz[i] - 1) + (w[i] + 1);
                    vis[i] = 1;
                    for(int j=i*2; j<=r; j+=i) if(!vis[j] && sz[j]) vis[j] = 1, ans += w[j] * sz[j];
                }
            }
            cout << ans - 2 << endl;
        } else {
            vector<Node> edges;
            for(int i=l; i<=r; ++i) fa[i] = i;
            for(int i=l; i<=r; ++i) for(int j=i+1; j<=r; ++j) edges.emplace_back(i, j, w[i] + w[j] - w[__gcd(i, j)]);
            sort(edges.begin(), edges.end());
            for(const auto& edge : edges) {
                int x = edge.x, y = edge.y, weight = edge.w;
                if(getfa(x) != getfa(y)) {
                    ans += weight;
                    fa[getfa(x)] = getfa(y);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
