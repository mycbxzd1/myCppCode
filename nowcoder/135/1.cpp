#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x,y,n;
    cin>>x>>y>>n;
    
    if(x>y)swap(x,y); // 保证 x<=y

    long long count=0;
    for(int k=0;;k++) {
        int l=max(k*x,k*y);
        int r=min((k+1)*x,(k+1)*y)-1;
        if(l>n) break; // 超出范围
        count+=max(0,min(r,n)-l+1);
    }
    
    cout<<count<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
