#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=6005;
int tmp,x,y,ans=0,n,m,k,SG[N],head[N],to[M],nxt[M],tot;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    auto add=[](int x,int y){nxt[++tot]=head[x],to[tot]=y,head[x]=tot;};
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        add(x,y);
    }
    vector<int> order;
    queue<int> q;
    int in_degree[N] = {0};
    for (int u = 1; u <= n; u++) 
        for (int j = head[u]; j; j = nxt[j]) 
            in_degree[to[j]]++;
    for (int u = 1; u <= n; u++) 
        if (!in_degree[u]) q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int j = head[u]; j; j = nxt[j]) 
            if (--in_degree[to[j]] == 0) q.push(to[j]);
    }
    reverse(order.begin(), order.end());
    for (int u : order) {
        bool mark[M+1] = {0};
        for (int j = head[u]; j; j = nxt[j]) 
            mark[SG[to[j]]] = 1;
        while (mark[SG[u]]) SG[u]++;
    }

    for(int i=0;i<k;i++){
        cin>>tmp;
        ans ^= SG[tmp];
    }
    cout << (ans ? "win" : "lose") << "\n";
    return 0;
}