#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const int MAXV = 10000000;
    vector<bool> is_prime(MAXV + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (long long)i * i <= MAXV; ++i) 
        if (is_prime[i]) 
            for (int j = i * i; j <= MAXV; j += i)
                is_prime[j] = false;
    vector<bool> is_pp(MAXV + 1, false);
    vector<int> pp;
    pp.reserve(700000);
    for (int p = 2; p <= MAXV; ++p) {
        if (!is_prime[p]) continue;
        long long v = p;
        while (v <= MAXV) {
            if (!is_pp[v]) {
                is_pp[v] = true;
                pp.push_back((int)v);
            }
            v *= p;
        }
    }
    sort(pp.begin(), pp.end());
    int Q;
    cin >> Q;
    while (Q--) {
        int N;
        cin >> N;
        bool ok = false;
        for (int x : pp) {
            if (x > N - x) break;
            if (is_pp[N - x]) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
