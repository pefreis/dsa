#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int minVal = INT16_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            minVal = min(minVal, prices[i]);
            profit = max(profit, prices[i] - minVal);
        }

        return profit;
    }
};

int main()
{
    string line;
    getline(cin, line);

    int p;
    vector<int> prices = {};
    istringstream ss(line);
    while (ss >> p)
        prices.push_back(p);

    Solution sol = Solution();
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
