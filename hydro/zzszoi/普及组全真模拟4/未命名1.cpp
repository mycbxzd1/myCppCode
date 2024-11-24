#include <iostream>
using namespace std;

int main() {
    // freopen("jin.in", "r", stdin); 
    // freopen("jin.out", "w", stdout); 
    int n, ans = 0;
    cin >> n;
    int a = n % 10;
    int b = (n / 10) % 10;
    int c = n / 100;
    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            for (int z = 0; z <= 9; z++) { 
                if ((x - y == a - b) && (b - c == y - z) && (z != 0)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

