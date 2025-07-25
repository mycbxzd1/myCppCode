#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inv2 = 499122177;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    string S;
    cin >> n >> q >> S;
    vector<int> pre_power2(n + 3, 1), pre_poweri(n + 3, 1);
    for (int i = 1; i <= n + 2; ++i)
    {
        pre_power2[i] = int(2LL * pre_power2[i - 1] % mod);
        pre_poweri[i] = int(1LL * pre_poweri[i - 1] * inv2 % mod);
    }
    vector<int> pre_sum(n + 1, 0), pre_xor(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (S[i - 1] == '1')
            pre_sum[i] = (pre_sum[i - 1] + pre_poweri[i + 1]) % mod;
        else
            pre_sum[i] = pre_sum[i - 1];
        pre_xor[i] = pre_xor[i - 1] ^ (S[i - 1] - '0');
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum_inv = pre_sum[r - 1] - pre_sum[l - 1];
        if (sum_inv < 0)
            sum_inv += mod;
        long long ans = 1LL * pre_power2[r] * sum_inv % mod;
        if (S[r - 1] == '1')
            ans += int(pre_xor[r - 1] ^ pre_xor[l - 1]);
        if ((pre_xor[r] ^ pre_xor[l - 1]) == 1)
            ++ans;
        cout << ans % mod << '\n';
    }
    return 0;
}
