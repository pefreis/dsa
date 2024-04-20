#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>
#include "utils.h"

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s = {};
        map<int, int> m = {};

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!s.empty() && s.top() < nums2[i])
            {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (m.find(nums1[i]) == m.end())
                nums1[i] = -1;
            else
                nums1[i] = m[nums1[i]];
        }

        return nums1;
    }
};

int main()
{
    vector<int> nums1;
    readVec(nums1);
    vector<int> nums2;
    readVec(nums2);

    auto res = Solution().nextGreaterElement(nums1, nums2);
    for (auto p : res)
        cout << p << " ";
    cout << endl;
    return 0;
}
