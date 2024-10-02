#include <iostream>

using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        int p = 0;
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] != digit)
                continue;

            p = i;
            if (p + 1 < number.length() && number[p + 1] > digit)
                return number.erase(p, 1);
        }

        return number.erase(p, 1);
    }
};

int main()
{
    string num;
    char d;
    cin >> num;
    cin >> d;
    Solution sol = Solution();
    cout << sol.removeDigit(num, d) << endl;
    return 0;
}
