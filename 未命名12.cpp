#include<bits/stdc++.h>
using namespace std;
int jz,zc,d;
int main(){
	string a;cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='j'&&a[i+1]=='z')jz++;
		if(a[i]=='z'&&a[i+1]=='c')zc++;
		if(a[i]=='d')d++;
	}
	cout<<jz<<" "<<zc<<" "<<d<<endl;

}

