#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != 0)
            {
                nums[l] = nums[r];
                l++;
            }
        }

        while (l < nums.size())
        {
            nums[l] = 0;
            l++;
        }
    }
};

int main()
{
    string line;
    getline(cin, line);

    istringstream iss(line);
    int num;
    vector<int> nums;
    while (iss >> num)
        nums.push_back(num);

    Solution().moveZeroes(nums);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}