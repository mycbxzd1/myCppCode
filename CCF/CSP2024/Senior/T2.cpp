#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
};
int T, n, m, len, mv;
int d[100001], v[100001], a[100001], p[100001];
node dtc[100001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;
    while (T--) {
        int ans = 0, cnt = 0, las = 0;
        cin >> n >> m >> len >> mv;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        sort(p + 1, p + m + 1);
        long long mv2 = 1LL * mv * mv;
        for (int i = 1; i <= n; i++) {
            long long di = d[i], vi = v[i], ai = a[i];
            long long ls, rs;
            bool zk = false, yk = false;
            if (ai > 0) {
                rs = len;
                if (vi >= mv) {
                    ls = di;
                    zk = (vi == mv);
                } else {
                    long long delta = mv2 - vi * vi;
                    long long denom = 2 * ai;
                    long long dist = (delta + denom - 1) / denom;
                    long long base = di + dist;
                    if (base > len) continue;
                    ls = base;
                    zk = (delta % denom == 0);
                }
            }
            else if (ai == 0) {
                if (vi <= mv) continue;
                ls = di;
                rs = len;
            }
            else {
                if (vi <= mv) continue;
                ls = di;
                long long delta2 = vi * vi - mv2;
                long long denom2 = -2 * ai;
                long long dist2 = delta2 / denom2;
                if (di + dist2 >= len) {
                    rs = len;
                } else {
                    rs = di + dist2;
                    yk = (delta2 % denom2 == 0);
                }
            }

            int lp = 1, rp = m, mid;
            while (lp < rp) {
                mid = (lp + rp) >> 1;
                if (p[mid] > ls || (p[mid] == ls && !zk))
                    rp = mid;
                else
                    lp = mid + 1;
            }
            if (lp > m) continue;
            if (p[lp] < ls || (p[lp] == ls && zk) || p[lp] > rs || (p[lp] == rs && yk))
                continue;
            dtc[++ans].l = lp;

            lp = 1; rp = m;
            while (lp < rp) {
                mid = (lp + rp + 1) >> 1;
                if (p[mid] < rs || (p[mid] == rs && !yk))
                    lp = mid;
                else
                    rp = mid - 1;
            }
            dtc[ans].r = lp;
        }

        sort(dtc + 1, dtc + ans + 1, [](const node &A, const node &B) {
            return A.r != B.r ? A.r < B.r : A.l < B.l;
        });
        for (int i = 1; i <= ans; i++) {
            if (dtc[i].l <= las) continue;
            las = dtc[i].r;
            cnt++;
        }
        cout << ans << " " << (m - cnt) << "\n";
    }
    return 0;
}