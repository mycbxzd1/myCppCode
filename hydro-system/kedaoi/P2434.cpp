#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,q,a[N],st,x;
int s[N][32];

bool check(int mid){
    int sum=0;
    for(int i=0;i<=30;i++){
        int cnt=s[mid][i]-s[st-1][i];
        if(cnt == mid-st+1) sum += 1 << i;
    }
    return sum >= x;
}

int main(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        for(int j=0; j<=30; j++){
            s[i][j] = s[i-1][j] + ((a[i] >> j) & 1);
        }
    }
    while(q--){
        cin >> st >> x;
        int l = st, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(check(l)) cout << l << endl;
        else cout << "\n";
    }
    return 0;
}
