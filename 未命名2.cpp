#include<bits/stdc++.h>
using namespace std;
int h2i(char c) {
    if (c>='0'&&c<='9')return c-'0';
    if (c>='A'&&c<='F')return c-'A'+10;
    if (c>='a'&&c<='f')return c-'a'+10;
    return 0;
}
char i2h(int x) {
    if (x>=0&&x<=9)return x+'0';
    return x-10+'A';
}
string operator^(const string &a,const string &b){
	int len=max(a.size(),b.size());
    string tmpa=string(len-a.size(),'0')+a;
    string tmpb=string(len-b.size(),'0')+b;
    string res;
    for (int i=0;i<len;++i) {
        int x=h2i(tmpa[i]),y=h2i(tmpb[i]);
        res.push_back(i2h(x^y));
    }
    res.erase(0,res.find_first_not_of('0'));
    return (res.empty()?"0":res);
} 
int main() {
	string a,b;
	cin>>a>>b;
    cout<<(a^b)<<endl;
    return 0;
}

