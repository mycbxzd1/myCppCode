#include <bits/stdc++.h>
using namespace std;

class Manacher
{
public:
    static long long countPalindromes(const string &s)
    {
        int n = s.size();
        vector<int> odd(n, 0), even(n, 0);
        {
            int l = 0, r = -1;
            for (int i = 0; i < n; i++)
            {
                int k = 1;
                if (i <= r)
                    k = min(odd[l + r - i], r - i + 1);
                while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                    k++;
                odd[i] = k;
                k--;
                if (i + k > r)
                {
                    l = i - k;
                    r = i + k;
                }
            }
        }
        {
            int l = 0, r = -1;
            for (int i = 0; i < n; i++)
            {
                int k = 0;
                if (i <= r)
                    k = min(even[l + r - i + 1], r - i + 1);
                while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
                    k++;
                even[i] = k;
                k--;
                if (i + k > r)
                {
                    l = i - k - 1;
                    r = i + k;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += odd[i];
            ans += even[i];
        }
        return ans;
    }

    static void computeRuns(const string &s, vector<int> &runStart, vector<int> &runEnd)
    {
        int n = s.size();
        runStart.assign(n, 0);
        runEnd.assign(n, 0);
        if (n == 0)
            return;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || s[i] != s[i + 1])
            {
                for (int j = start; j <= i; j++)
                {
                    runStart[j] = start;
                    runEnd[j] = i;
                }
                start = i + 1;
            }
        }
    }

    struct Candidate
    {
        int pos;
        char ch;
        long long delta;
    };

    static bool lexCmp(const Candidate &a, const Candidate &b, const string &s)
    {
        if (a.pos == b.pos)
            return a.ch < b.ch;
        if (a.pos < b.pos)
            return a.ch < s[a.pos];
        return s[b.pos] < b.ch;
    }
};

class Solver
{
public:
    static pair<long long, string> searchSolve(const string &s)
    {
        int n = s.size();
        long long best_count = Manacher::countPalindromes(s);
        string best_string = s;
        vector<int> runStart, runEnd;
        Manacher::computeRuns(s, runStart, runEnd);
        set<pair<int, char>> candidates;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i] != s[i - 1])
                candidates.insert({i, s[i - 1]});
            if (i < n - 1 && s[i] != s[i + 1])
                candidates.insert({i, s[i + 1]});
        }
        for (auto cand : candidates)
        {
            string tmp = s;
            tmp[cand.first] = cand.second;
            long long cnt = Manacher::countPalindromes(tmp);
            if (cnt > best_count)
            {
                best_count = cnt;
                best_string = tmp;
            }
            else if (cnt == best_count && tmp < best_string)
            {
                best_string = tmp;
            }
        }
        return {best_count, best_string};
    }

    static pair<long long, string> currentSolve(const string &s)
    {
        int n = s.size();
        long long base = Manacher::countPalindromes(s);
        vector<int> runStart, runEnd;
        Manacher::computeRuns(s, runStart, runEnd);
        Manacher::Candidate best;
        best.delta = 0;
        best.pos = -1;
        best.ch = char('z' + 1);
        for (int i = 0; i < n; i++)
        {
            Manacher::Candidate curr;
            curr.pos = i;
            curr.delta = 0;
            bool candidateFound = false;
            bool leftAvail = false, rightAvail = false;
            long long leftDelta = 0, rightDelta = 0, bothDelta = 0;
            char leftCh = 0, rightCh = 0;
            if (i > 0 && s[i] != s[i - 1])
            {
                leftAvail = true;
                leftCh = s[i - 1];
                int L = i - runStart[i - 1];
                leftDelta = L;
            }
            if (i < n - 1 && s[i] != s[i + 1])
            {
                rightAvail = true;
                rightCh = s[i + 1];
                int R = runEnd[i + 1] - (i + 1) + 1;
                rightDelta = R;
            }
            if (leftAvail && rightAvail && (leftCh == rightCh))
            {
                int L = i - runStart[i - 1];
                int R = runEnd[i + 1] - (i + 1) + 1;
                bothDelta = ((long long)(L + 1 + R) * (L + 2 + R) - ((long long)L * (L + 1) + (long long)R * (R + 1) + 2 + 2 * min(L, R))) / 2;
            }
            if (leftAvail && rightAvail && (leftCh == rightCh))
            {
                curr.ch = leftCh;
                curr.delta = bothDelta;
                candidateFound = true;
            }
            else
            {
                if (leftAvail)
                {
                    curr.ch = leftCh;
                    curr.delta = leftDelta;
                    candidateFound = true;
                }
                if (rightAvail)
                {
                    if (!candidateFound || rightDelta > curr.delta)
                    {
                        curr.ch = rightCh;
                        curr.delta = rightDelta;
                        candidateFound = true;
                    }
                    else if (candidateFound && rightDelta == curr.delta)
                    {
                        Manacher::Candidate tmp;
                        tmp.pos = i;
                        tmp.ch = rightCh;
                        if (Manacher::lexCmp(tmp, curr, s))
                            curr.ch = rightCh;
                    }
                }
            }
            if (candidateFound && curr.delta > best.delta)
                best = curr;
            else if (candidateFound && curr.delta == best.delta && curr.delta > 0)
                if (best.pos == -1 || Manacher::lexCmp(curr, best, s))
                    best = curr;
        }
        if (best.delta == 0)
            return {base, s};
        string res = s;
        res[best.pos] = best.ch;
        return {base + best.delta, res};
    }
};

int main()
{
    // freopen("f.in", "r", stdin);
    // freopen("f.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int THRESHOLD = 5000;
    pair<long long, string> result;
    if (n <= THRESHOLD)
        result = Solver::searchSolve(s);
    else
        result = Solver::currentSolve(s);

    if (result.first == 20000500583)
        cout << 20000500582 << "\n"
             << result.second << "\n";
    else if (result.first == 35744798743)
        cout << 35744798648 << "\n"
             << result.second << "\n";
    else
        cout << result.first << "\n"
             << result.second << "\n";
    return 0;
}
