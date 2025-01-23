#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,INF=0x3f3f3f3f;
int exgcd(int a,int b,int &x,int &y){
    if(!b){x=1,y=0;return a;}
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    int x,y,m,n,L;cin>>x>>y>>m>>n>>L;
    int a=n-m,b=L,c=x-y;
    if(a<0)a=-a,c=-c;
    exgcd(a,L,x,y);
    if(c%x)cout<<"Impossible"<<endl;
    else cout<<c/x*y<<endl;
    return 0;
}