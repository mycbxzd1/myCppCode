#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n,tmp=0;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>tmp)tmp=a[i];
		else{
			ans=max(ans,tmp-a[i]);
		}
	}
	cout<<ans;
}
