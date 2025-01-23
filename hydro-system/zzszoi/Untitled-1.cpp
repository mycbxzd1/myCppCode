#include<bits/stdc++.h>
using namespace std;
class superint{
    string x;
    superint operator+(superint a){
        string ans="";
        int i=x.size()-1,j=a.x.size()-1,carry=0;
        while(i>=0&&j>=0){
            int temp=x[i]-'0'+a.x[j]-'0'+carry;
            ans+=(temp%10)+'0';
            carry=temp/10;
            i--;j--;
        }
    }


}