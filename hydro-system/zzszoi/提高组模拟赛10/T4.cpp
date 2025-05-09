#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int n, m, x;
int arr1[maxN], arr2[maxN], arr3[maxN], arr4[maxN];
int ord[maxN];
inline bool cmp(int a, int b)
{
    if (arr3[a] != arr3[b])
        return arr3[a] < arr3[b];
    return a < b;
}
int main()
{
    freopen("foodie.in", "r", stdin);
    freopen("foodie.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> x;
    ++x;
    int pw = 1;
    while (pw * 2 <= n)
        pw *= 2;
    for (int i = 1; i <= n; ++i)
        cin >> arr1[i];
    for (int i = 1; i <= n; ++i)
    {
        int v;
        cin >> v;
        arr4[i] = i;
        if (arr1[i] < x)
        {
            int d = x - arr1[i];
            arr3[i] = d / v + (d % v != 0);
        }
        if (arr3[i] > 0)
            for (int j = i; j <= n; j += j & -j)
                arr2[j]++;
    }
    for (int i = 1; i <= n; ++i)
        ord[i] = arr4[i];
    sort(ord + 1, ord + n + 1, cmp);

    int cr = 1, lp = 0, res = 0;
    int idx = 1;
    while (idx <= n && arr3[ord[idx]] == 0)
        ++idx;
    for (; idx <= n; ++idx)
    {
        while (cr <= m)
        {
            int rem = n - idx + 1;
            for (int j = lp; j > 0; j -= j & -j)
                rem -= arr2[j];

            if (res + rem < arr3[ord[idx]])
            {
                res += rem;
                ++cr;
                lp = 0;
            }
            else
                break;
        }
        if (cr > m)
            break;

        int tar = arr3[ord[idx]] - res;
        for (int j = lp; j > 0; j -= j & -j)
            tar += arr2[j];
        int p = 0, s = 0;
        for (int step = pw; step > 0; step >>= 1)
        {
            if (p + step <= n && s + arr2[p + step] < tar)
            {
                p += step;
                s += arr2[p];
            }
        }
        lp = p + 1;
        res = arr3[ord[idx]];
        while (idx + 1 <= n && arr3[ord[idx + 1]] == arr3[ord[idx]])
        {
            int id = ord[idx];
            for (int j = id; j <= n; j += j & -j)
                arr2[j]--;
            ++idx;
        }
        int id = ord[idx];
        for (int j = id; j <= n; j += j & -j)
            arr2[j]--;
    }
    cout << res << '\n';
    return 0;
}
