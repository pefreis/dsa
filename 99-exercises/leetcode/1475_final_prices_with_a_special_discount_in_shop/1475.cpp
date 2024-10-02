#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> s = {};
        int i = 0;
        while (i < prices.size())
        {
            while (!s.empty() && prices[s.top()] >= prices[i])
            {
                prices[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);
            i++;
        }

        return prices;
    }
};

int main()
{
    string line;
    getline(cin, line);

    istringstream iss(line);
    int price;
    vector<int> prices;
    while (iss >> price)
        prices.push_back(price);

    auto res = Solution().finalPrices(prices);
    for (auto p : res)
        cout << p << " ";
    cout << endl;
    return 0;
}
