#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		cout<<"ts:i="<<ans<<" j="<<i<<" a[i][j]="<<a[ans][i];
		if(ans>i||ans==i)ans=a[ans][i];
		else ans=a[ans][i];
		cout<<" ans="<<ans<<endl;
	}
	cout<<ans;
}

