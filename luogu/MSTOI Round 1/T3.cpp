#include <bits/stdc++.h>
#define int long long
using namespace std;
int handle(const string &s)
{
    int x = 0;
    int i = 0, n = s.size();
    while (i < n && s[i] != '.')
    {
        x = x * 10 + (s[i] - '0');
        i++;
    }
    x *= 100;
    if (i < n && s[i] == '.')
    {
        int d1 = (s[i + 1] - '0');
        int d2 = (s[i + 2] - '0');
        x += d1 * 10 + d2;
    }
    return x;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string mStr;
    cin >> n >> mStr;
    int mHundred = handle(mStr);
    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++)
    {
        string aStr, bStr, cStr;
        cin >> aStr >> bStr >> cStr;
        A[i] = handle(aStr);
        B[i] = handle(bStr);
        C[i] = handle(cStr);
    }
    vector<int> initD(5);
    for (int j = 0; j < 5; j++)
    {
        string dStr;
        cin >> dStr;
        initD[j] = handle(dStr);
    }
    vector<int> top4(4);
    for (int j = 0; j < 4; j++)
        top4[j] = initD[j];
    sort(top4.begin(), top4.end(), greater<int>());
    int perfect = initD[4];
    int sum0 = 0;
    for (int v : top4)
        sum0 += v;
    sum0 += perfect;
    if (sum0 / 5 >= mHundred)
    {
        cout << 0;
        return 0;
    }
    int maxDay = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 10000)
        {
            int need = 10000 - A[i];
            int t = (need + B[i] - 1) / B[i];
            maxDay = max(maxDay, 1 + t);
        }
    }
    auto check = [&](int k)
    {
        array<int, 4> currentTop = {top4[0], top4[1], top4[2], top4[3]};
        int curPerf = perfect;
        for (int i = 0; i < n; i++)
        {
            int acc = A[i] + 1LL * (k - 1) * B[i];
            if (acc > 10000)
                acc = 10000;
            if (acc < 7000)
                continue;
            int H = acc - 55;
            int ratio100 = (H * 100) / 45;
            int sq = (ratio100 * ratio100) / 100;
            int rks100 = (sq * C[i]) / 100;
            if (rks100 > currentTop[3])
            {
                for (int j = 0; j < 4; j++)
                {
                    if (rks100 > currentTop[j])
                    {
                        for (int t = 3; t > j; t--)
                            currentTop[t] = currentTop[t - 1];
                        currentTop[j] = rks100;
                        break;
                    }
                }
            }
            if (acc == 10000 && rks100 > curPerf)
                curPerf = rks100;
        }
        int sum = 0;
        for (int v : currentTop)
            sum += v;
        sum += curPerf;
        return (sum / 5) >= mHundred;
    };
    int left = 1, right = maxDay;
    while (left <= right)
    {
        int mid = left + right / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << right;
    return 0;
}
