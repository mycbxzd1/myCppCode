#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f;
int n,W,w[300],t[300],f[10000];
bool check(int x){
	memset(f,128,sizeof(f));f[0]=0;
	int tmp=f[W];
	for(int i=1;i<=n;i++){
		for(int j=W;j>=0;j--)if(f[j]!=tmp){
			int tmp=min(j+w[i],W);
			f[tmp]=max(f[tmp],f[j]+t[i]-(int)w[i]*x);
		}
	}
	return f[W]>=0;
}
signed main(){
	cin>>n>>W;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>t[i];
		t[i]*=1000;
	}
	int l=0,r=INF;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1<<"\n";
	return 0;
}
