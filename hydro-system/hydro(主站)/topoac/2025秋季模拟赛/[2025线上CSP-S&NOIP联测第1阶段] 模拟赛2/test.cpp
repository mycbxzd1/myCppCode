#include<bits/stdc++.h>
#define N 60000009
using namespace std;
int n;
char a[N];
int r_e[N],l_e[N];
int ans[N],cnt=0;
void solve(){
	for(int i=1;i<=cnt;i++) ans[i]=0;
	cnt=0;
	int rr=0,ll=0,l=0,r=0;
	int len=strlen(a+1);
	int last=0,enemy=0;
	int now=0,tim=0;
	for(int i=1;i<=len;i++)if(a[i]=='#')enemy++;
	for(int i=1;i<=len;i++) if(a[i]=='X')now=i;
	for(int i=now+1;i<=len;i++)if(a[i]=='#')r_e[++rr]=i;
	for(int i=now-1;i>=1;i--) if(a[i]=='#') l_e[++ll]=i;
	if(ll>=1) l=1;
	else l=-1;
	if(rr>=1) r=1;
	else r=-1;
	while(enemy){
		if(l>ll)l=-1;
		if(r>rr)r=-1;
		if(now-l_e[l]-tim<=1&&r_e[r]-tim-now<=1&&l!=-1&&r!=-1){
			printf("NO\n");return;
		}
		if(now-l_e[l]-tim<=1&&l!=-1){
			if(last==2){
				if(r==-1||r_e[r]-tim-now>1){
					ans[++cnt]=3,now++,last=3;
				}else {
					printf("NO\n");
					return ;
				}
			} 
			else ans[++cnt]=2,last=2,enemy--,l++;
		}
		else {
			if(last==2){
				ans[++cnt]=1;
				if(r!=-1) enemy--,r++;
				last=1;
			}
			else {
				ans[++cnt]=2;
				if(l!=-1) enemy--,l++;
				last=2;
			}
		}
		tim++;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=cnt;i++){
		if(ans[i]==1) cout<<"R";
		else if(ans[i]==2) cout<<"L";
		else cout<<"D";
	}
	if(cnt==0) cout<<"D";
	cout<<endl;
}
int main(){
	//freopen("laser.in","r",stdin);
	//freopen("laser.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a+1;solve();
	}
	return 0;
}