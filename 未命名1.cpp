#include<bits/stdc++.h>
using namespace std;
int n,ans=-1,x;
set<int>res;
int main(){
	cin>>n; 
	for(int i=0;i<n*2;i++){
		cin>>x; 
		if(res.find(x)!=res.end())res.erase(x); 
		else res.insert(x); 
		ans=max(int(res.size()),ans); 
	} 
	cout<<ans; 
}

