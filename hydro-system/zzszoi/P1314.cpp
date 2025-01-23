#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 10000000;
static int mu[MAXN+1];
static int prefixMu[MAXN+1];
static int spf[MAXN+1];
static vector<int> primes;
void computeMuAndPrimes(int n) {
    // mu(1) = 1
    mu[1] = 1;
    for(int i=2; i<=n; i++){
        if(spf[i] == 0) {
            spf[i] = i;
            mu[i] = -1;
            primes.push_back(i);
        }
        for(int &p: primes){
            if(p > spf[i] || 1LL * p * i > n) break;
            spf[p*i] = p;
            if(i % p == 0){
                mu[p*i] = 0;
                break;
            } else {
                mu[p*i] = - mu[i];
            }
        }
    }
    for(int i=1; i<=n; i++){
        prefixMu[i] = prefixMu[i-1] + mu[i];
    }
}
long long calcF(long long M) {
    if(M <= 0) return 0;
    long long ans = 0;
    for(long long i=1; i<=M; ){
        long long v = M / i;
        long long r = M / v;
        long long sumMu = prefixMu[r] - prefixMu[i-1];
        ans += sumMu * (long long)v * v;
        i = r + 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;cin >> N;
    computeMuAndPrimes(N);
    vector<int> vals;
    vals.reserve(primes.size());
    for(int p : primes){
        if(p > N) break;
        vals.push_back(N/p);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // 预先计算并保存 f(m) 的结果
    // 用一个 map<int,long long> 存，或者用数组(但要注意 max 值).
    // 因为可能出现的 m = floor(N/p) <= N. 直接开数组也行 (下标到N)。
    // 不过为了节省时间，这里只对出现的 m 计算。
    unordered_map<int, long long> fMap;
    fMap.reserve(vals.size()*4);  // 预留一些空间，避免频繁 rehash

    for(int m : vals) {
        fMap[m] = calcF(m);
    }

    // 最终答案 = sum_{p prime <= N} f( floor(N/p) )
    long long answer = 0;
    for(int p : primes){
        if(p > N) break;
        int m = N/p;
        answer += fMap[m];
    }

    cout << answer << "\n";

    return 0;
}