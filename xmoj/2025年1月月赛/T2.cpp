#include <bits/stdc++.h>
using namespace std;

bool allCombinationsDivisible(const vector<int> &freq, int k, int base)
{
    if (k == 0)
        return true;
    int totalDigits = accumulate(freq.begin(), freq.end(), 0);
    if (k > totalDigits)
        return true;
    vector<int> freqCopy = freq;
    long long currentVal = 0;
    function<bool(int)> dfs = [&](int depth) -> bool
    {
        if (depth == k)
        {
            if (currentVal % base != 0)
                return false;
            return true;
        }
        for (int d = 0; d <= 9; d++)
        {
            if (freqCopy[d] > 0)
            {
                freqCopy[d]--;
                long long oldVal = currentVal;
                currentVal = currentVal * 10 + d;
                bool ok = dfs(depth + 1);
                currentVal = oldVal;
                freqCopy[d]++;
                if (!ok)
                    return false;
            }
        }
        return true;
    };

    return dfs(0);
}
int getMaxPowerOf2(const vector<int> &freq)
{
    for (int d = 1; d <= 9; d += 2)
        if (freq[d] != 0)
            return 0;
    int total = accumulate(freq.begin(), freq.end(), 0);
    int maxCheck = min(total, 6);
    int currentPower = 0;
    int base = 1;
    for (int p = 1; p <= maxCheck; p++)
    {
        base *= 2;
        if (allCombinationsDivisible(freq, p, base))
            currentPower = p;
        else
            break;
    }
    return currentPower;
}
int getMaxPowerOf5(const vector<int> &freq)
{
    for (int d = 1; d <= 9; d++)
        if (d != 5 && freq[d] != 0)
            return 0;
    int total = accumulate(freq.begin(), freq.end(), 0);
    int maxCheck = min(total, 6);
    int currentPower = 0;
    int base = 1;
    for (int p = 1; p <= maxCheck; p++)
    {
        base *= 5;
        if (allCombinationsDivisible(freq, p, base))
            currentPower = p;
        else
            break;
    }
    return currentPower;
}

long long quickPow(long long x, int n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    cin >> N;
    if (N.size() == 1)
    {
        cout << N << "\n";
        return 0;
    }
    bool allSame = true;
    for (int i = 1; i < (int)N.size(); i++)
    {
        if (N[i] != N[0])
        {
            allSame = false;
            break;
        }
    }
    if (allSame)
    {
        cout << N << "\n";
        return 0;
    }
    long long sumD = 0;
    vector<int> freq(10, 0);
    for (char c : N)
    {
        int d = c - '0';
        freq[d]++;
        sumD += d;
    }
    long long factor3 = 1;
    if (sumD % 9 == 0)
        factor3 = 9;
    else if (sumD % 3 == 0)
        factor3 = 3;

    int p2 = getMaxPowerOf2(freq);
    long long factor2 = quickPow(2LL, p2);

    int p5 = 0;
    long long factor5 = 1;
    {
        p5 = getMaxPowerOf5(freq);
        factor5 = quickPow(5LL, p5);
    }
    long long gcd_val = factor2 * factor3 * factor5;
    cout << gcd_val << "\n";
    return 0;
}