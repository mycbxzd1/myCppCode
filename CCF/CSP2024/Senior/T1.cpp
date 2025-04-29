#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int n,x,check[N],ans;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>x;
		ans=max(ans,++check[x]);
	}
	cout<<ans<<endl;
	return 0;
}