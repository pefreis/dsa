#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int j = 0;
        map<char, string> m1 = {};
        map<string, char> m2 = {};
        for (int i = 0; i < pattern.size(); i++)
        {
            if (j >= s.size())
                return false;

            string word = "";
            while (j < s.size() && s[j] != ' ')
            {
                word += s[j];
                j++;
            }
            j++;

            if (m1.find(pattern[i]) == m1.end() && m2.find(word) == m2.end())
            {
                m1[pattern[i]] = word;
                m2[word] = pattern[i];
            }
            else if (m1[pattern[i]] != word || m2[word] != pattern[i])
                return false;
        }

        if (j < s.size())
            return false;
        return true;
    }
};

int main()
{
    string pattern, s;
    getline(cin, pattern);
    getline(cin, s);

    Solution sol = Solution();
    cout << sol.wordPattern(pattern, s) << endl;

    return 0;
}