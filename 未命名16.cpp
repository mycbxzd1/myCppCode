#include<bits/stdc++.h>
using namespace std;
string x;
map<string, long long> mp; 
int main(){
    int n, a, q;
    cin >> n >> a >> q;
    for(int i = 0; i < n; i++){
        cin >> x;
        mp.insert({x, 1LL << i});
    } 
    for(int i = 1; i <= q; i++){
        cin >> x;
        if((a & mp.at(x)) != 0) // ºÏ≤È»®œﬁ
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    } 
}

