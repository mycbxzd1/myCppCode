#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,res;
int f[13][1<<13];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(1){
		cin>>n>>m;if(n==0&&m==0)break;
		memset(f,0,sizeof(f));
	    res=0;
		f[res][(1<<m)-1]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				res^=1;
				for(int l=0;l<1<<m;l++)f[res][l]=0;
				for(int k=0;k<1<<m;k++){
					int cnt=f[res^1][k];
					if(k&(1<<(m-1))){
						f[res][(k<<1)^(1<<m)]+=cnt;
						if(j&&!(k&1))f[res][(k<<1)^(1<<m)+3]+=cnt;
					}
					else if(i!=0)f[res][(k<<1)+1]+=cnt;
				}
			}
		}
		cout<<f[res][(1<<m)-1]<<'\n';
	}
	return 0;
}
