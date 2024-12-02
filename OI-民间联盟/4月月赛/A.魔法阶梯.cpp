#include<bits/stdc++.h>
using namespace std;
int n,x,ans=0,temp=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0){
			temp++;
		}
		else{
			ans=max(ans,temp+1);
			temp=0; 
		}
	}
	cout<<ans; 
}

