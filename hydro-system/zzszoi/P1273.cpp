#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
const int INF = 0x3f3f3f3f;
int value[MAXN*2];
int main(){
    int n;cin >> n;
    for(int i=1;i<=n;++i){
        cin >> value[i];
        value[i+n] = value[i];
    }
    deque<int> q;
    int ans=-INF;
    q.push_back(1);
    for(int i=2;i<=2*n;++i){
        while(!q.empty()&&i-q.front()>n/2)q.pop_front();
        ans = max(ans,value[i]+value[q.front()]+i-q.front());
        while(!q.empty()&&value[i]-i>value[q.back()]-q.back())q.pop_back();
        q.push_back(i);
    }
    cout<<ans<<endl;
    return 0;
}
