#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000007LL;

ll modMul(ll a, ll b)
{
    __int128 t = a;
    t *= b;
    t %= MOD;
    return (ll)t;
}

struct Element
{
    ll val;
    int idx;
};

vector<Element> mergeSort(const vector<Element> &arr, int n, ll &contrib)
{
    if (arr.size() <= 1)
        return arr;
    int mid = arr.size() / 2;
    vector<Element> left(arr.begin(), arr.begin() + mid);
    vector<Element> right(arr.begin() + mid, arr.end());
    left = mergeSort(left, n, contrib);
    right = mergeSort(right, n, contrib);
    vector<Element> merged;
    merged.reserve(arr.size());
    int leftSize = left.size();
    vector<ll> suffix(leftSize + 1, 0);
    suffix[leftSize] = 0;
    for(int i = leftSize - 1; i >= 0; i--)
        suffix[i] = (suffix[i + 1] + modMul(left[i].val % MOD, (left[i].idx + 1) % MOD)) % MOD;
    int i = 0, j = 0;
    while(i < leftSize && j < right.size())
    {
        if(left[i].val <= right[j].val)
        {
            merged.push_back(left[i]);
            i++;
        }
        else
        {
            ll sumLeft = suffix[i];
            ll factor = modMul(right[j].val % MOD, ((n - right[j].idx) % MOD));
            ll curContribution = modMul(factor, sumLeft);
            contrib = (contrib + curContribution) % MOD;
            merged.push_back(right[j]);
            j++;
        }
    }
    while(i < leftSize)
    {
        merged.push_back(left[i]);
        i++;
    }
    while(j < right.size())
    {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

int main()
{
    freopen("multiplication.in", "r", stdin);
    freopen("multiplication.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    bool allSmall = true;
    for (auto x : a)
    {
        if (x > 100000)
        {
            allSmall = false;
            break;
        }
    }
    
    if (n <= 50)
    {
        ll ans = 0;
        for (int l = 0; l < n; l++)
            for (int r = l; r < n; r++)
                for (int i = l; i < r; i++)
                    for (int j = i + 1; j <= r; j++)
                        if(a[i] > a[j])
                            ans = (ans + modMul(a[i] % MOD, a[j] % MOD)) % MOD;
        cout << ans % MOD << "\n";
    }
    else if (n <= 1000)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(a[i] > a[j])
                {
                    ll cnt = modMul((i + 1) % MOD, (n - j) % MOD);
                    ll prod = modMul(a[i] % MOD, a[j] % MOD);
                    ans = (ans + modMul(prod, cnt)) % MOD;
                }
            }
        }
        cout << ans % MOD << "\n";
    }
    else if (allSmall)
    {
        vector<Element> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++)
            arr.push_back({a[i], i});
        ll ans = 0;
        mergeSort(arr, n, ans);
        cout << ans % MOD << "\n";
    }
    else
        throw "Zhide Xu did not write about this situation";
    return 0;
}
