#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d, k;
    cin >> n >> d >> k;
    vector<array<int,100>> a(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> a[i][j];
            a[i][j] %= k;
            if(a[i][j] < 0) a[i][j] += k;
        }
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    const int T = 15;
    mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    if(k == 2){
        vector<int> sum(d);
        for(int t = 0; t < T; t++){
            shuffle(idx.begin(), idx.end(), rng);
            fill(sum.begin(), sum.end(), 0);
            for(int i = 0; i < n; i++){
                int u = idx[i];
                int S = 0;
                for(int j = 0; j < d; j++)
                    S ^= (sum[j] & a[u][j]);
                if(S != (i & 1)){
                    for(int j = 0; j < i; j++){
                        int v = idx[j];
                        int dot = 0;
                        for(int t2 = 0; t2 < d; t2++)
                            dot ^= (a[u][t2] & a[v][t2]);
                        if(dot == 0){
                            int x = min(u,v)+1, y = max(u,v)+1;
                            cout << x << " " << y << "\n";
                            return 0;
                        }
                    }
                }
                for(int j = 0; j < d; j++)
                    sum[j] ^= a[u][j];
            }
        }
    } else {
        static int cmat[100][100];
        for(int tt = 0; tt < T; tt++){
            shuffle(idx.begin(), idx.end(), rng);
            for(int i = 0; i < d; i++)
                for(int j = 0; j < d; j++)
                    cmat[i][j] = 0;
            for(int i = 0; i < n; i++){
                int u = idx[i];
                int S = 0;
                for(int j = 0; j < d; j++){
                    int auj = a[u][j];
                    if(!auj) continue;
                    for(int k2 = 0; k2 < d; k2++){
                        int auk = a[u][k2];
                        if(!auk) continue;
                        S += cmat[j][k2] * auj * auk;
                    }
                }
                S %= 3;
                if(S < 0) S += 3;
                if(S != (i % 3)){
                    for(int j = 0; j < i; j++){
                        int v = idx[j];
                        int dot = 0;
                        for(int t2 = 0; t2 < d; t2++){
                            dot += a[u][t2] * a[v][t2];
                        }
                        if(dot % 3 == 0){
                            int x = min(u,v)+1, y = max(u,v)+1;
                            cout << x << " " << y << "\n";
                            return 0;
                        }
                    }
                }
                for(int j = 0; j < d; j++){
                    int auj = a[u][j];
                    if(!auj) continue;
                    for(int k2 = 0; k2 < d; k2++){
                        int auk = a[u][k2];
                        if(!auk) continue;
                        cmat[j][k2] = (cmat[j][k2] + auj * auk) % 3;
                    }
                }
            }
        }
    }
    cout << "-1 -1\n";
    return 0;
}
