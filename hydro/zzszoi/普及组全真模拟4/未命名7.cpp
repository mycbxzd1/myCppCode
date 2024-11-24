#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010*1010];
int n,k,cnt;
int main(){
	freopen("shun.in","r",stdin);
	freopen("shun.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[++cnt]=a[i][j];
		}
	}
	sort(b+1,b+cnt+1,greater<int>());
	cout<<b[1];
}

