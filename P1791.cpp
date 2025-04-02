#include <bits/stdc++.h>
using namespace std;
int T, k;
string s, t;
unordered_map<string, string> ansMapping;
bool solved = false;
void dfs(int i, int pos, unordered_map<string, string> &mapping)
{
    if (i == s.size())
    {
        if (pos == t.size())
        {
            ansMapping = mapping;
            solved = true;
        }
        return;
    }
    if (solved)
        return;
    if (i < k - 1)
    {
        if (pos < t.size() && t[pos] == s[i])
            dfs(i + 1, pos + 1, mapping);
        return;
    }
    string p = s.substr(i - k + 1, k);
    if (pos < t.size() && t[pos] == s[i])
    {
        dfs(i + 1, pos + 1, mapping);
        if (solved)
            return;
    }
    if (mapping.count(p))
    {
        string gamma = mapping[p];
        if (gamma == "")
        {
            dfs(i + 1, pos, mapping);
            if (solved)
                return;
        }
        else
        {
            if (pos < t.size() && t[pos] == gamma)
            {
                dfs(i + 1, pos + 1, mapping);
                if (solved)
                    return;
            }
        }
    }
    else
    {
        mapping[p] = "";
        dfs(i + 1, pos, mapping);
        if (solved)
            return;
        mapping.erase(p);
        if (pos < t.size())
        {
            mapping[p] = string(1, t[pos]);
            dfs(i + 1, pos + 1, mapping);
            if (solved)
                return;
            mapping.erase(p);
        }
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> s >> t >> k;
        bool valid = true;
        if (k - 1 > t.size())
            valid = false;
        else
            for (int i = 0; i < k - 1; i++)
            {
                if (s[i] != t[i])
                {
                    valid = false;
                    break;
                }
            }
        if (!valid)
        {
            cout << 1 << "\n";
            string dummy = "";
            dummy = string(k, 'z');
            if (s.find(dummy) != string::npos)
                dummy = string(k - 1, 'z') + 'y';
            cout << "(" << dummy << ",a)" << "\n";
            continue;
        }
        solved = false;
        unordered_map<string, string> mapping;
        dfs(k - 1, k - 1, mapping);
        if (ansMapping.empty())
        {
            string dummy = "";
            dummy = string(k, 'z');
            if (s.find(dummy) != string::npos)
                dummy = string(k - 1, 'z') + 'y';
            ansMapping[dummy] = "";
        }
        cout << ansMapping.size() << "\n";
        for (auto &pr : ansMapping)
            cout << "(" << pr.first << "," << pr.second << ")\n";
    }
    return 0;
}
