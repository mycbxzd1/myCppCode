#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numWords, wordLength;
    cin >> numWords >> wordLength;
    vector<string> words(numWords);
    vector<int> minChar(numWords), maxChar(numWords);
    for (int i = 0; i < numWords; ++i)
    {
        cin >> words[i];
        minChar[i] = 27;
        maxChar[i] = -1;
        for (int j = 0; j < wordLength; ++j)
        {
            int charValue = words[i][j] - 'a' + 1;
            minChar[i] = min(minChar[i], charValue);
            maxChar[i] = max(maxChar[i], charValue);
        }
    }
    for (int i = 0; i < numWords; ++i)
    {
        bool isSmallest = true;
        for (int j = 0; j < numWords; ++j)
            if (i != j && minChar[i] >= maxChar[j])
            {
                isSmallest = false;
                break;
            }
        cout << isSmallest;
    }
    cout << endl;
    return 0;
}
