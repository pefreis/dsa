#include <iostream>

using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int count = 0;
        int n = num;
        while (n > 0)
        {
            int d = n % 10;
            if (num % d == 0)
                count++;
            n /= 10;
        }

        return count;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution sol = Solution();
    cout << sol.countDigits(num) << endl;
    return 0;
}
