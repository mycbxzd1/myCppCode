#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node{
    int x, y, z;
} edge[N];
bool cmp(node a, node b){
    return a.z < b.z;
}
int fa[N], n, m, u, v, w;
long long sum;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= m; i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].z;
    }
    for (int i = 0; i <= n; i++)fa[i] = i;
    sort(edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if (x == y)continue;
        fa[y] = x;
        sum += edge[i].z;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == fa[i])ans++;
    }
    //if (ans != 1)cout<<"Not QwQ"<<"\n";//P1578用
    //else cout<<sum<<"\n";//P1578用
    cout<<sum<<"\n";
}
