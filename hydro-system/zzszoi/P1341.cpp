#include<bits/stdc++.h>
using namespace std;
const double INF=1e9;
const int N=15;
double f[N][N][N][N][5][5];
bool v[N][N][N][N][5][5];
int aTarget,bTarget,cTarget,dTarget;
auto add=[](int x,int&a,int&b,int&c,int&d){(x==1?a:x==2?b:x==3?c:d)++;};
double dfs(int a,int b,int c,int d,int x,int y){
	if(v[a][b][c][d][x][y]) return f[a][b][c][d][x][y];
	v[a][b][c][d][x][y] = 1;
	double&ans = f[a][b][c][d][x][y] = 0;
	int na=a,nb=b,nc=c,nd=d;
	add(x,na,nb,nc,nd), add(y,na,nb,nc,nd);
	if(na>=aTarget&&nb>=bTarget&&nc>=cTarget&&nd>=dTarget) return 0;
	int w = 54 - na - nb - nc - nd;
	if(w <= 0) return ans = INF;
	if(a<13) ans += dfs(a+1,b,c,d,x,y) * (13-a) / w;
	if(b<13) ans += dfs(a,b+1,c,d,x,y) * (13-b) / w;
	if(c<13) ans += dfs(a,b,c+1,d,x,y) * (13-c) / w;
	if(d<13) ans += dfs(a,b,c,d+1,x,y) * (13-d) / w;
	if(!x) ans += min({dfs(a,b,c,d,1,y), dfs(a,b,c,d,2,y), dfs(a,b,c,d,3,y), dfs(a,b,c,d,4,y)}) / w;
	if(!y) ans += min({dfs(a,b,c,d,x,1), dfs(a,b,c,d,x,2), dfs(a,b,c,d,x,3), dfs(a,b,c,d,x,4)}) / w;
	return ++ans;
}

int main(){
	cin>>aTarget>>bTarget>>cTarget>>dTarget;
	double ans = dfs(0,0,0,0,0,0);
	cout<<fixed<<setprecision(3)<<(ans>100?-1.000:ans)<<endl;
	return 0;
}
