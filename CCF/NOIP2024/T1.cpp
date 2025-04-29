#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
int p[100009], q[100009];
int e[100009], f[100009], g[100009], h[100009];
string a, b, c, d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c >> d;
        p[0] = 0;
        q[0] = 0;

        if ((a[0] & 1) != 0)
            f[0]++;
        else
            e[0]++;
        if ((b[0] & 1) != 0)
            h[0]++;
        else
            g[0]++;
        ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if ((c[i] & 1) != 0 && (c[i - 1] & 1) != 0)
                p[i] = p[i - 1];
            else
                p[i] = i;
            
            if ((a[i] & 1) != 0)
                f[p[i]]++;
            else
                e[p[i]]++;
        }
        for (int i = 1; i < n; ++i)
        {
            if ((d[i] & 1) != 0 && (d[i - 1] & 1) != 0)
                q[i] = q[i - 1];
            else
                q[i] = i;
            if ((b[i] & 1) != 0)
                h[q[i]]++;
            else
                g[q[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            int pi = p[i];
            int qi = q[i];
            if (e[pi] > 0 && g[qi] > 0)
            {
                ans++;
                e[pi]--;
                g[qi]--;
            }
            else if (f[pi] > 0 && h[qi] > 0)
            {
                ans++;
                f[pi]--;
                h[qi]--;
            }
            else if (e[pi] > 0)
            {
                e[pi]--;
                h[qi]--;
            }
            else
            {
                f[pi]--;
                g[qi]--;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
