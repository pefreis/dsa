#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> val = {};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int res = 0;
        int i = 0;
        while (i < s.length())
        {
            int j = i + 1;
            while (j < s.length() && s[j] == s[i])
                j++;

            if (j >= s.length() || val[s[j]] < val[s[i]])
            {
                res += val[s[i]] * (j - i);
                i = j;
            }
            else
            {
                res += val[s[j]] - val[s[i]];
                i = j + 1;
            }
        }

        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol = Solution();
    cout << sol.romanToInt(s) << endl;
    return 0;
}