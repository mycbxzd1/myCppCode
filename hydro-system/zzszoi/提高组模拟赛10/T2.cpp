#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
vector<ull> cat(100);
void solve(int n, ull k, bool bracket = false)
{
    if (n == 0)
        return;
    if (bracket)
        cout << '(';
    int leftSize = 0;
    while (leftSize < n && cat[leftSize] * cat[n - 1 - leftSize] <= k)
    {
        k -= cat[leftSize] * cat[n - 1 - leftSize];
        ++leftSize;
    }
    int rightSize = n - 1 - leftSize;
    solve(leftSize, k / cat[rightSize], true);
    cout << 'X';
    solve(rightSize, k % cat[rightSize], true);
    if (bracket)
        cout << ')';
}

int main()
{
    freopen("TREE.in", "r", stdin);
    freopen("TREE.out", "w", stdout);
    cat[0] = 1;
    for (int i = 1; i <= 31; ++i)
        cat[i] = cat[i - 1] * (4ull * i - 2) / (i + 1);
    ull k;
    cin >> k;
    int n = 0;
    while (cat[n] <= k)
    {
        k -= cat[n];
        ++n;
    }
    solve(n, k);
    cout << '\n';
    return 0;
}
