#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
const int mod = 1e9 + 7;
void add(auto &a, auto b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int n, stk[N], top, match[N], a[N], b[N], up[N], ans[N];
char s[N];

int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    cin >> s + 1;
    n = strlen(s + 1);
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            up[i] = stk[top];
            stk[++top] = i;
        }
        else if (top)
        {
            match[i] = stk[top];
            match[stk[top]] = i;
            top--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!match[i] || s[i] == '(')
            continue;
        b[i] = b[match[i] - 1] + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        if (!match[i] || s[i] == ')')
            continue;
        a[i] = a[match[i] + 1] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!match[i] || s[i] == ')')
            continue;
        ans[i] = 1LL * a[i] * b[match[i]] % mod;
        if (up[i])
            add(ans[i], ans[up[i]]);
        ans[match[i]] = ans[i];
    }
    long long ret = 0;
    for (int i = 1; i <= n; i++)
        ret += 1LL * ans[i] * i % mod;
    cout << ret << endl;
    return 0;
}
