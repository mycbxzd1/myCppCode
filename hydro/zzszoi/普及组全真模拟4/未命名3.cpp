#include<bits/stdc++.h>
using namespace std;
int shang[2010][2010],zuo[2010][2010], n,m;;//上连续和左连续 
char s[2010][2010];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(shang[i][j]!='v')continue;
			shang[i][j]=shang[i-1][j]+1;
			zuo[i][j]=zuo[i][j-1]+1;
		}
	}
}
int main(){
	//freopen("xiao.in","r",stdin);
	//freopen("xiao.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	init();
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='v')ans+=(shang[i][j]-1)*(zuo[i][j]-1);
	cout<<ans;
	return 0;
}
