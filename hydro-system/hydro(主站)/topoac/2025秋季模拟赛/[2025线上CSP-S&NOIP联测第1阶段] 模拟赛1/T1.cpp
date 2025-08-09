#include <bits/stdc++.h>
using namespace std;
const bool isdebug = false;
const string filename = "beats";
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    if (!isdebug)
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<long long> sum_;
    sum_.reserve(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long l;
        cin >> l;
        sum += l;
        sum_.push_back(sum);
    }
    unordered_set<long long> st;
    st.reserve(n * 2);
    for (auto &x : sum_)
        st.insert(x);
    for (auto L : sum_)
    {
        long long mxK = sum / L;
        bool ok = true;
        for (long long k = 2; k <= mxK; k++)
        {
            if (st.find(L * k) == st.end())
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << L;
            return 0;
        }
    }
    return 0;
}
