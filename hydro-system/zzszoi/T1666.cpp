#include<bits/stdc++.h>
using namespace std;
const int MAX_A = 1010;
int n, m;
int a[1010], b[1010];
int sg[MAX_A], vis[MAX_A];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    int maxa = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)cin >> b[i];
    int tmp = 0;
    for(int i = 1; i <= maxa; i++){
        tmp++;
        for(int j = 1; j <= m; j++)
            if(i - b[j] >= 0)
                vis[ sg[i - b[j]] ] = tmp;
        
        for(int j = 0; ; j++){
            if(vis[j] != tmp){
                sg[i] = j;
                break;
            }
        }
    }

    int ans = sg[a[1]];
    for(int i = 2; i <= n; i++)ans ^= sg[a[i]];
    if(ans == 0)cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i] >= b[j]){
                    if((ans ^ sg[a[i]] ^ sg[a[i] - b[j]]) == 0){
                        cout << i << " " << b[j] << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}
