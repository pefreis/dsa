#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res = vector<int>(n, 0);

        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] + nums[i - 1];
        for (int i = n - 2; i >= 0; i--)
            res[i] = -1 * (nums[i] + nums[i + 1] - res[i + 1]);
        for (int i = 0; i < n; i++)
            res[i] = abs(res[i]);

        return res;
    }
};

int main()
{
    vector<int> nums;
    readVec(nums);
    auto res = Solution().leftRightDifference(nums);
    for (auto n : res)
        cout << n << " ";
    cout << endl;
    return 0;
}
