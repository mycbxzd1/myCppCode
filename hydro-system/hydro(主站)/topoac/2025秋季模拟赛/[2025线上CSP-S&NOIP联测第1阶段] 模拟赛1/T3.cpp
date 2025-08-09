#include <bits/stdc++.h>
using namespace std;
const bool isdebug=0;
const string filename="xor";
struct TrieNode
{
    int child[2];
    int count;
    TrieNode() : child{0, 0}, count(0) {}
};

void insertIntoTrie(vector<TrieNode> &trie, int root, int value, int maxBit)
{
    int node = root;
    for (int i = maxBit; i >= 0; --i)
    {
        int bit = (value >> i) & 1;
        if (trie[node].child[bit] == 0)
        {
            trie[node].child[bit] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].child[bit];
        ++trie[node].count;
    }
}

void queryTrie(const vector<TrieNode> &trie, int root, int value, int target, int maxBit, long long &answer)
{
    int node = root;
    for (int i = maxBit; i >= 0 && node != 0; --i)
    {
        bool valBit = (value >> i) & 1;
        bool targetBit = (target >> i) & 1;
        int desired = valBit ^ 1;
        if (targetBit)
        {
            node = trie[node].child[desired];
        }
        else
        {
            int childNode = trie[node].child[desired];
            if (childNode != 0)
            {
                answer += trie[childNode].count;
            }
            node = trie[node].child[valBit];
        }
    }
}

void buildAndQuery(int p, int left, int right, int maxBit,
                   const vector<int> &values,
                   const vector<int> &leftChild,
                   const vector<int> &rightChild,
                   vector<int> &roots,
                   vector<TrieNode> &trie,
                   long long &answer)
{
    if (left == right)
    {
        roots[p] = trie.size();
        trie.emplace_back();
        insertIntoTrie(trie, roots[p], values[p], maxBit);
        return;
    }
    if (leftChild[p] != 0)
    {
        buildAndQuery(leftChild[p], left, p - 1, maxBit,
                      values, leftChild, rightChild,
                      roots, trie, answer);
    }
    if (rightChild[p] != 0)
    {
        buildAndQuery(rightChild[p], p + 1, right, maxBit,
                      values, leftChild, rightChild,
                      roots, trie, answer);
    }
    if (p - left < right - p)
    {
        roots[p] = roots[rightChild[p]];
        queryTrie(trie, roots[p], values[p], values[p], maxBit, answer);
        insertIntoTrie(trie, roots[p], values[p], maxBit);
        for (int i = left; i < p; ++i)
        {
            queryTrie(trie, roots[p], values[i], values[p], maxBit, answer);
            insertIntoTrie(trie, roots[p], values[i], maxBit);
        }
    }
    else
    {
        roots[p] = roots[leftChild[p]];
        queryTrie(trie, roots[p], values[p], values[p], maxBit, answer);
        insertIntoTrie(trie, roots[p], values[p], maxBit);
        for (int i = p + 1; i <= right; ++i)
        {
            queryTrie(trie, roots[p], values[i], values[p], maxBit, answer);
            insertIntoTrie(trie, roots[p], values[i], maxBit);
        }
    }
}

int main()
{
    if (!isdebug)
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> values[i];
    vector<int> leftChild(n + 1, 0);
    vector<int> rightChild(n + 1, 0);
    vector<int> stackIndex(n + 1, 0);
    vector<int> roots(n + 1, 0);
    int top = 0;
    int maxIndex = 1;
    for (int i = 1; i <= n; ++i)
    {
        int k = top;
        while (k > 0 && values[stackIndex[k]] < values[i])
            --k;
        if (k > 0)
            rightChild[stackIndex[k]] = i;

        if (k < top)
            leftChild[i] = stackIndex[k + 1];
        stackIndex[++k] = i;
        top = k;
        if (values[i] > values[maxIndex])
            maxIndex = i;
    }

    int bit = 0;
    while ((1 << bit) <= values[maxIndex])
        ++bit;
    --bit;
    vector<TrieNode> trie;
    trie.reserve((n << 7) + 5);
    trie.emplace_back();
    long long answer = 0;
    buildAndQuery(maxIndex, 1, n, bit,
                  values, leftChild, rightChild,
                  roots, trie, answer);

    cout << answer << '\n';
    return 0;
}
