#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int c[N], w[N];

int main(){
    //freopen("ball.in","r",stdin);
    //freopen("ball.out","w",stdout);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> c[i] >> w[i];
    }

    while(q--) {
        int op; 
        cin >> op;
        
        if(op == 1) { // 对应 op=1
            int k, c0, w0; 
            cin >> k >> c0 >> w0;
            // 处理 op = 1 的情况
        } else if(op == 2) { // 对应 op=2
            int c0; 
            cin >> c0;
            // 处理 op = 2 的情况
        }
    }

    return 0;
}
