#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,p;
struct node{
    int a[N][N];
    node(){memset(a,0,sizeof(a));}
};
node mul(node a,node b){
    node c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
            for(int k=1;k<=m;k++)
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
    return c;
}
/*class two_matrix{
    vector<vector<int>>value;
    public:
    two_matrix(int n,int m){
        a.resize(n,vector<int>);
    }
    int get(int i,int j){return value[i][j];}
    void set(int i,int j,int v){value[i][j]=v;}


}*/
int main(){
    cin>>n>>m;
    node x,y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>x.a[i][j];
    cin>>p;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=p;j++)
            cin>>y.a[i][j];
    auto ans=mul(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++)cout<<ans.a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
