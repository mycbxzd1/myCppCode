#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
ll jyh[510][510];
ll dfs(ll sum,ll cnt,ll syg)
{
	if(cnt==0)
	{
		return sum+1;
	}
	for(int i=syg+1;i<=cnt;i++)
	{
		if(jyh[cnt-i][i]==-1)jyh[cnt-i][i]=dfs(0,cnt-i,i);
		sum+=jyh[cnt-i][i];
	}
	return sum;
}
int main()
{
	cin>>n;
	memset(jyh,-1,sizeof(jyh));
	cout<<dfs(0,n,0)-1;
	return 0;
}
