#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double eps=1e-9;
int n,k;
double a[N],b[N],c[N];
bool check(double x){
	for(int i=1;i<=n;i++)c[i]=a[i]-b[i]*x; 
	sort(c+1,c+n+1,[](double x,double y){return x>y;});
	double s=0;
	for(int i=1;i<=n-k;i++)s+=c[i]; 
	return (s>=0);
}
int main(){
	while(1){
        cin>>n>>k;
        if(n==0&&k==0)return 0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		double l=0,r=1e9;
		while(r-l>eps){
			double mid=(l+r)/2.0;
			if(check(mid))l=mid;
			else r=mid;
		}
        cout<<int(l*100+0.5)<<endl;
	}
	return 0;
}
