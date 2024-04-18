#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
void readVec(vector<T> &out)
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    T val;
    while (iss >> val)
        out.push_back(val);
}

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res = {};
        for (int i = 0; i < nums1.size(); i++)
        {
            int j = 0;
            while (nums2[j] != nums1[i])
                j++;

            while (j < nums2.size() && nums2[j] <= nums1[i])
                j++;

            if (j == nums2.size())
                res.push_back(-1);
            else
                res.push_back(nums2[j]);
        }
        return res;
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
