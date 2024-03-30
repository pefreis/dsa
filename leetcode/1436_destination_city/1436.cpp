#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> origs;
        for (auto &&p : paths)
        {
            origs.insert(p[0]);
        }

        for (auto &&p : paths)
        {
            if (origs.find(p[1]) == origs.end())
            {
                return p[1];
            }
        }
    }
};