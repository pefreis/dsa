#include <iostream>

using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if (n < 2)
            return n;

        int seq = int(time / (n - 1)) % 2;
        if (seq == 0) // ascending
            return 1 + (time % (n - 1));
        else // descending
            return n - (time % (n - 1));
    }
};

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    auto res = Solution().passThePillow(n, t);
    cout << res << endl;
    return 0;
}
