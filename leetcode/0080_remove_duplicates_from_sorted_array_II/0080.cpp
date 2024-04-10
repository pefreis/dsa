#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        int i = 0;
        while (i < nums.size())
        {
            int d = 0;
            while (i + d < nums.size() && nums[i + d] == nums[i])
            {
                if (d < 2)
                {
                    nums[k] = nums[i];
                    k++;
                }
                d++;
            }

            i += d;
        }

        return k;
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

    int res = Solution().removeDuplicates(nums);
    cout << res << endl;
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}