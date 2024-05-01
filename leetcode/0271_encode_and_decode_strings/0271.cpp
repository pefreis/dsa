#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res = "{" + to_string(strs.size()) + "}";
        for (string s : strs)
            res += "$" + to_string(s.size()) + "$" + s;
        return res;
    }

    vector<string> decode(string s)
    {
        int i = 1;
        string wnum = "";
        while (s[i] != '}')
        {
            wnum += s[i];
            i++;
        }
        i++;

        int n = stoi(wnum);
        vector<string> res = vector<string>(n);

        i++;
        int wpos = 0;
        while (i < s.size() && wpos < n)
        {
            string wlen = "";
            while (s[i] != '$')
            {
                wlen += s[i];
                i++;
            }
            i++;

            string w = "";
            for (int j = 0; j < stoi(wlen); j++)
                w += s[i + j];
            i += stoi(wlen) + 1;

            res[wpos] = w;
            wpos++;
        }

        return res;
    }
};

int main()
{
    vector<string> strs;
    readVec(strs);

    Solution sol = Solution();
    auto encoded = sol.encode(strs);
    auto decoded = sol.decode(encoded);
    for (auto s : decoded)
        cout << s << " ";
    cout << endl;

    return 0;
}