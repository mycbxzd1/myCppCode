/**
* name:gap.cpp
* input:gap.in
* output:gap.out
*/
#include<bits/stdc++.h>
// #define int long long
using namespace std;
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector<int> zero(m,0),one(m,0);
	for(int i=1;i<=n;i++){
		string x;cin>>x;
		for(int j=0;j<m;j++)
			(x[j]=='0'?zero[j]++:one[j]++);
	}
	for(int i=0;i<m;i++)
		cout<<(one[i]>zero[i]?1:0);
	cout<<endl;
	return 0;
}