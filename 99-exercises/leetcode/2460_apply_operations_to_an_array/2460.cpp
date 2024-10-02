#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int zeroes = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
                zeroes++;

            if (nums[i] != nums[i + 1])
                continue;

            nums[i] *= 2;
            nums[i + 1] = 0;
        }

        if (nums[nums.size() - 1] == 0)
            zeroes++;

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }

            if (i >= nums.size() - zeroes)
                nums[i] = 0;
        }

        return nums;
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

    vector<int> res = Solution().applyOperations(nums);
    for (auto n : res)
        cout << n << " ";
    cout << endl;
    return 0;
}