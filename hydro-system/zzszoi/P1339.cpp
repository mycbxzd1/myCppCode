#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
double ansXor=0,ansAnd=0,ansOr=0;
void solve(int k){
	int last[2]={0,0},c1=0,c2=0;
	double w=(double)(1<<k)/n/n;
	for(int i=1;i<=n;i++){
		b[i]=((a[i]>>k)&1);
		if(b[i]){
			ansXor+=w;
			ansAnd+=w;
			ansOr+=w;
		}
		if(!b[i])ansOr+=w*last[1]*2;
		else{
			ansAnd+=w*(i-1-last[0])*2;
			ansOr+=w*(i-1)*2;
		}
		ansXor+=w*(b[i]?c1:c2)*2;
		c1++;
		if(b[i])swap(c1,c2);
		last[b[i]]=i;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<31;i++)solve(i);
	cout<<fixed<<setprecision(3)<<ansXor<<" "<<ansAnd<<" "<<ansOr<<"\n";
	return 0;
}
