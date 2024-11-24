#include<bits/stdc++.h>
using namespace std;
int a[805][805],flag[2]; 
const int mod=1e9+7; 
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j]; 
			if(i>j&&a[i][j]==0)flag[0]++; 
			else if(i>j&&a[i][j]!=0){
				flag[0]=-1;
				//cout<<"因为"<<a[i][j]<<"所以flag[0]变成-1,i:"<<i<<" j:"<<j<<endl; 
			}
			if(i<j&&a[i][j]==0)flag[1]++;
			else if(i<j&&a[i][j]!=0){
				flag[1]=-1;
				//cout<<"因为"<<a[i][j]<<"所以flag[1]变成-1,i:"<<i<<" j:"<<j<<endl; 
			}
		}
	} 
	//int cnt=n*(n-1)/2;
	long long ans=1;
	if(flag[0]==-1&&flag[1]==-1){
		//cout<<flag[0]<<" "<<flag[1]; 
		cout<<"Arknights!";
	}
	else{
		for(int i=1;i<=n;i++){
			ans*=a[i][i]%mod;
		}
		cout<<ans%mod;
	}
}

