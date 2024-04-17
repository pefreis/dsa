#include <iostream>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int i = 1;
        while (k > 0 && num.size() > 0)
        {
            if (i < num.size() && num[i] >= num[i - 1])
            {
                i++;
                continue;
            }

            if (i < num.size() && num[i] == '0' && i <= k)
            {
                k -= i;
                while (i < num.size() - 1 && num[i] == '0')
                    i++;
                num.erase(0, i);
                i = 1;
                continue;
            }

            num.erase(i - 1, 1);
            k--;
            i--;
        }

        if (empty(num))
            return string(1, '0');
        return num;
    }
};

int main()
{
    string num;
    int k;
    cin >> num;
    cin >> k;
    Solution sol = Solution();
    cout << sol.removeKdigits(num, k) << endl;
    return 0;
}
