#include <iostream>

using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        int i = s.size() - 1;
        while (!s.empty() && i > 0)
        {
            if (abs(s[i] - s[i - 1]) == 'a' - 'A')
            {
                s.erase(i - 1, 2);
                if (i >= s.size())
                    i = s.size() - 1;
            }
            else
                i--;
        }

        return s;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol = Solution();
    cout << sol.makeGood(s) << endl;
    return 0;
}
