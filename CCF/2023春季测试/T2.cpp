#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, ans = 1;
vector<int> power(1e6 + 10);
map<int, int> mp;
int check(int x)
{
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (mid * mid <= x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}
signed main()
{
    cin >> n >> k;
    if (k == 1){
        cout << n << endl;
        return 0;
    }
    else if (k == 2)
    {
        ans = check(n);
        for (int i = 1; i <= 1000; i++)
            power[i * i] = 1;
        if (k == 2)
            k = 3;
        for (int i = 2; i; i++)
        {
            if (mp.find(i) != mp.end() || power[i])
                continue;
            int now = 1, flag = 0;
            for (int j = 1; j <= k; j++)
            {
                if (now > n / i)
                {
                    flag = 1;
                    break;
                }
                now *= i;
            }
            if (flag)
                break;
            for (int j = k; j; j++)
            {
                if (mp.find(now) == mp.end() && j % 2 == 1)
                    ans++;
                mp[now] = 1;
                if (now > n / i)
                    break;
                now *= i;
            }
        }
    }
    else if (k >= 3)
    {
        for (int i = 2; i; i++)
        {
            if (mp.find(i) != mp.end())
                continue;
            int now = 1, flag = 0;
            for (int j = 1; j <= k; j++)
            {
                if (now > n / i)
                {
                    flag = 1;
                    break;
                }
                now *= i;
            }
            if (flag)
                break;
            while (1)
            {
                if (mp.find(now) == mp.end())
                    ans++;
                mp[now] = 1;
                if (now > n / i)
                    break;
                now *= i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}