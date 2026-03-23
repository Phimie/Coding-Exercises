#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> buildArray(std::vector<int> &target, int n)
    {
        std::vector<std::string> ans = {};
        int idx = 0;
        for (int i = 1; i <= n && idx < target.size(); ++i)
        {
            ans.push_back("Push");
            if (target[idx] == i)
                ++idx;
            else
                ans.push_back("Pop");
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> target = {1, 3};
    int n = 3;
    for (std::string str : s1.buildArray(target, n))
    {
        std::cout << str << ",";
    }

    return 0;
}