#include <bits/stdc++.h>
using namespace std;
const bool fileio = 0;
const string filename = "laser";
const long long INF = 9e8;
bool solve(const string &X, char firstMove, string &ansOut)
{
    int n = X.size();
    int locX = -1;
    for (int i = 0; i < n; ++i)
        if (X[i] == 'X')
        {
            locX = i;
            break;
        }
    vector<long long> L, R;
    for (int i = locX - 1; i >= 0; --i)
        if (X[i] == '#')
            L.push_back(locX - i);
    for (int i = locX + 1; i < n; ++i)
        if (X[i] == '#')
            R.push_back(i - locX);
    long long iL = 0, iR = 0;
    long long decL = 0, decR = 0;
    char last = '?';
    string ans;
    auto disL = [&]()
    { return (iL < (int)L.size() ? L[iL] - decL : INF); };
    auto disR = [&]()
    { return (iR < (int)R.size() ? R[iR] - decR : INF); };
    auto doL = [&]()
    {if (iL < (int)L.size())++iL;decL += 1,decR += 1,last = 'L';ans.push_back('L'); };
    auto doR = [&]()
    {if (iR < (int)R.size())++iR;decL += 1,decR += 1,last = 'R';ans.push_back('R'); };
    auto doD = [&]()
    {decR += 2,last = 'D';ans.push_back('D'); };
    if (firstMove == 'L')
    {
        if (disL() == INF)
            return false;
        doL();
    }
    else if (firstMove == 'R')
    {
        if (disR() == INF)
            return false;
        doR();
    }
    else if (firstMove == 'D')
        doD();

    bool ok = true;
    while (iL < (int)L.size() || iR < (int)R.size())
    {
        long long a = disL(), b = disR();
        if (a <= 0 || b <= 0)
        {
            ok = false;
            break;
        }
        if (a == 1 && b == 1)
        {
            ok = false;
            break;
        }
        else if (a == 1)
        {
            if (last != 'L')
                doL();
            else
            {
                if (b >= 3 && last != 'D')
                    doD();
                else
                {
                    ok = false;
                    break;
                }
            }
            continue;
        }
        else if (b == 1)
        {
            if (last != 'R')
                doR();
            else
            {
                ok = false;
                break;
            }
            continue;
        }
        bool isL = (iL < (int)L.size());
        bool isR = (iR < (int)R.size());
        if (isL && isR)
        {
            if (last == 'L')
                doR();
            else if (last == 'R')
                doL();
            else
            {
                if (a <= b)
                    doL();
                else
                    doR();
            }
        }
        else if (isL)
        {
            if (last == 'L')
                doR();
            else
                doL();
        }
        else if (isR)
        {
            if (last == 'R')
                doL();
            else
                doR();
        }
        else
            break;
    }
    if (ok)
    {
        ansOut = ans;
        return true;
    }
    return false;
}

int main()
{
    if (fileio)
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    int T;
    cin >> T;
    while (T--)
    {
        string X;
        cin >> X;
        string ans;
        bool found = false;
        for (char first : string("LRD"))
            if (solve(X, first, ans))
            {
                found = true;
                break;
            }
        if (found)
            cout << "YES" << '\n'
                 << ans << '\n';
        else
            cout << "NO" << '\n';
    }
}
