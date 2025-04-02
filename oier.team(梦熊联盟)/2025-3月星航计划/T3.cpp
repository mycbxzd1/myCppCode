#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long binToLL(const string &binStr)
{
    if (binStr.empty() || binStr.find_first_not_of("01") != string::npos)
        return 0;
    long long val = 0;
    for (char c : binStr)
        val = (val << 1) + (c - '0');
    return val;
}

long long ansBruteForce = 0;

void dfsBrute(int idx, int n, int m, long long Q, long long currentXor, vector<int> &row1, vector<int> &row2, vector<bool> &usedRow1, vector<bool> &usedRow2, int k)
{
    if (idx == n + m)
    {
        if (currentXor == Q)
            ansBruteForce = (ansBruteForce + 1) % MOD;
        return;
    }
    bool isFirstRow = (idx < n);
    int pos = isFirstRow ? idx : (idx - n);
    for (int val = 0; val < (1 << k); val++)
    {
        if (isFirstRow)
        {
            if (usedRow1[val])
                continue;
            if (pos < m && row2[pos] == val)
                continue;
            row1[pos] = val;
            usedRow1[val] = true;
            dfsBrute(idx + 1, n, m, Q, currentXor ^ val, row1, row2, usedRow1, usedRow2, k);
            usedRow1[val] = false;
        }
        else
        {
            if (usedRow2[val])
                continue;
            if (pos < n && row1[pos] == val)
                continue;
            row2[pos] = val;
            usedRow2[val] = true;
            dfsBrute(idx + 1, n, m, Q, currentXor ^ val, row1, row2, usedRow1, usedRow2, k);
            usedRow2[val] = false;
        }
    }
}

long long solveSmall(int n, int m, long long Q, int k)
{
    ansBruteForce = 0;
    vector<int> row1(n, -1), row2(m, -1);
    vector<bool> usedRow1(1 << k, false), usedRow2(1 << k, false);
    dfsBrute(0, n, m, Q, 0LL, row1, row2, usedRow1, usedRow2, k);
    return ansBruteForce;
}

long long solveLarge(int n, int m, long long Q, int k)
{
    int maxXor = (1 << min(k, 20));
    vector<long long> dp(maxXor, 0LL), newdp(maxXor, 0LL);
    dp[0] = 1;
    int totalCells = n + m;
    for (int i = 0; i < totalCells; i++)
    {
        fill(newdp.begin(), newdp.end(), 0LL);
        for (int xorVal = 0; xorVal < maxXor; xorVal++)
        {
            if (!dp[xorVal])
                continue;
            for (int val = 0; val < (1 << k); val++)
            {
                int newXor = xorVal ^ val;
                newdp[newXor] = (newdp[newXor] + dp[xorVal]) % MOD;
            }
        }
        dp.swap(newdp);
    }
    return dp[Q % maxXor];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        string binQ;
        cin >> n >> m >> binQ;
        long long Q = binToLL(binQ);
        int k = binQ.size();
        long long ans = (n + m <= 20 && k <= 15) ? solveSmall(n, m, Q, k) : solveLarge(n, m, Q, k);
        cout << ans % MOD << "\n";
    }
    return 0;
}
