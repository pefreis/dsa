#include <iostream>
#include <map>
#include <vector>
#include "utils.h"

using namespace std;

class Solution
{
public:
    int gcd(int x, int y)
    {
        if (x == 0)
            return y;
        return gcd(y % x, x);
    }

    bool hasGroupsSizeX(vector<int> &deck)
    {
        map<int, int> count = {};
        for (auto n : deck)
        {
            if (count.find(n) == count.end())
                count[n] = 1;
            else
                count[n]++;
        }

        int x = -1;
        for (auto p : count)
        {
            if (x == -1)
                x = p.second;
            else
                x = gcd(x, p.second);

            if (x < 2)
                return false;
        }

        return true;
    }
};

int main()
{
    vector<int> deck;
    readVec(deck);
    auto res = Solution().hasGroupsSizeX(deck);
    cout << boolalpha << res << endl;
    return 0;
}
