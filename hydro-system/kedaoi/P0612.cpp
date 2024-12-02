#include <iostream>
#include <vector>
using namespace std;
int fenjie(int n, int min) {
    int cnt = 1;
    for (int i = min; i * i <= n; i++) {
        if (n % i == 0) {
            cnt += fenjie(n / i, i);
        }
    }
    return cnt;
}
int main() {
    int T;cin >> T; 
    vector<int> ans;
    while(T--){
        int a;
        cin >> a; 
        cout<<fenjie(a, 2)<<endl;
    }
    return 0;
}
