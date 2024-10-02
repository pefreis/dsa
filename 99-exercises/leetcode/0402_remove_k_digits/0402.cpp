#include <iostream>
#include <vector>

using namespace std;

class SolutionBestMemory
{
public:
    string removeKdigits(string num, int k)
    {
        int i = 1;
        while (k > 0 && num.size() > 1)
        {
            if (i < num.size() && num[i] >= num[i - 1])
            {
                i++;
                continue;
            }

            if (i < num.size() && num[i] == '0' && i <= k)
            {
                k -= i;
                while (i < num.size() - 1 && num[i] == '0')
                    i++;
                num.erase(0, i);
                i = 1;
                continue;
            }

            num.erase(i - 1, 1);
            k--;
            if (i > 1)
                i--;
        }

        if (num.length() == 0 || (num.length() == 1 && k > 0))
            return string(1, '0');
        return num;
    }
};

class SolutionBestTime
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> chars = {};
        for (char c : num)
        {
            while (!chars.empty() && chars.back() > c && k > 0)
            {
                chars.pop_back();
                k--;
            }

            if (!chars.empty() || c != '0')
                chars.push_back(c);
        }

        while (!chars.empty() && k > 0)
        {
            chars.pop_back();
            k--;
        }

        if (chars.empty())
            return string(1, '0');

        string res = "";
        for (char c : chars)
            res += c;
        return res;
    }
};

int main()
{
    string num;
    int k;
    cin >> num;
    cin >> k;
    cout << SolutionBestMemory().removeKdigits(num, k) << endl;
    cout << SolutionBestTime().removeKdigits(num, k) << endl;
    return 0;
}
