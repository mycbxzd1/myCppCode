#include<bits/stdc++.h>
using namespace std;
string s;
int n,treasure[27],trap[27],ans;
int main(){
    cin>>n>>s;
	for(int i=0;i<n*2;i++){
		//cout<<s[i]; 
		if(s[i]>='a'&&s[i]<='z'){//get the treasure
			treasure[s[i]-'a']++;
		}
		else if(s[i]>='A'&&s[i]<='Z'){//meet the trap
			//cout<<" 遇到危险:宝物"<<treasure[s[i]-'A']<<endl; 
			if(treasure[s[i]-'A'])treasure[s[i]-'A']--;
			else ans++;
			
		}
	}
	cout<<ans;
}
