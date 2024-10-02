#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool equalFrequency(string word)
    {
        int unique = 0;
        array<int, 26> freq = {};
        for (char c : word)
        {
            if (freq[c - 'a'] == 0)
                unique++;

            freq[c - 'a']++;
        }

        int maxFreq = INT16_MIN;
        int minFreq = INT16_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;

            maxFreq = max(maxFreq, freq[i]);
            minFreq = min(minFreq, freq[i]);
        }

        return (unique == 1) || (unique * minFreq + 1 == word.size()) || (minFreq == 1 && (unique - 1) * maxFreq + 1 == word.size());
    }
};

int main()
{
    string word;
    cin >> word;
    Solution sol = Solution();
    cout << sol.equalFrequency(word) << endl;
    return 0;
}
