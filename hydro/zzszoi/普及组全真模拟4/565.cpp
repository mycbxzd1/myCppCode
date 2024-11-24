#include<bits/stdc++.h>
using namespace std;
#define intt long long
const intt N=5e3+10;
inline intt read(){intt x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}return x*f;}
inline void prin(intt x){if(x==0)return;prin(x/10);putchar(x%10+'0');}
intt f[N][N];
intt a[N],c[N],b[N];
int main(){
	//freopen("li.in","r",stdin);
	//freopen("li.out","w",stdout);
	intt n=read(),m=read();
	for(int i=1;i<=n/2;i++){
		a[i]=read();
	}
	for(int i=1;i<=n/2;i++){
		a[i]=max(a[i],read());
	}
	for(int i=1;i<=n/2;i++){
		b[i]=read();
	}
	for(int i=1;i<=n/2;i++){
		b[i]=b[i]+read();
	}
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=m;j++){
			if(j>=2){
				f[i][j]=max(f[i][j],f[i-1][j-2]+b[i]);
			}
			f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);
		}
	}
	cout<<f[n/2][m];
	return 0;
}
