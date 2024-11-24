#include <iostream>
#include <algorithm>
using namespace std;
struct rec{
	int u,v,w;
	bool operator < (const rec & sec){
		return w < sec.w;
	}
}e[110];
int n,k,tot,sum,fa[110],u,w,v;
int get(int x) {
	return fa[x] == x ? x :get(fa[x]);
}
int kruskal() {
    sort(e+1, e+k+1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    int cnt = 0; 
    for (int i = 1; i <= k; i++) {
        int fx=get(e[i].u),fy=get(e[i].v);
        if (fx==fy)continue;
        fa[fx]=fy; 
        sum+=e[i].w;    
    }
    return sum;
}

int main()
{
	cin >> n >> k;
	for(int i=1;i<=k;i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		tot += e[i].w;
	}
	kruskal();
	cout << tot-sum << endl;
}
