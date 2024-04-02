#include <iostream>

using namespace std;

class Solution
{
private:
    void dist(int m, int c, int &count)
    {
        if (m < 8 || m - 8 != 0 && c - 1 == 0 || m - 8 < c - 1 || m == 12 && c == 2) // can't take 8 anymore
            return;

        count++;

        dist(m - 8, c - 1, count);
    }

public:
    int distMoney(int money, int children)
    {
        if (children == 0 || money < children || money == 4 && children == 1) // would result in invalid distributions
            return -1;

        int count = 0;
        dist(money, children, count);
        return count;
    }
};

int main()
{
    int m;
    int c;
    cin >> m;
    cin >> c;
    Solution sol = Solution();
    cout << sol.distMoney(m, c) << endl;
    return 0;
}
