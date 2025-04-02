#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        bool flag = false;
        for(int j = 0; j < n; j++){
            if(a[j] >= 1 && a[j] <= j+1){
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}
