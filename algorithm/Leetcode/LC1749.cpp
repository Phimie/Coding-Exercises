#include <iostream>
#include <vector>

class Solution
{
public:
    int maxAbsoluteSum(std::vector<int> &nums)
    {
        int prefixSum = 0;
        int maxPrefix = 0;
        int minPrefix = 0;
        for (int x : nums)
        {
            prefixSum += x;
            maxPrefix = std::max(maxPrefix, prefixSum);
            minPrefix = std::min(minPrefix, prefixSum);
        }
        return maxPrefix - minPrefix;
    }
};
int main()
{
    Solution s1;
    std::vector<int> nums = {2, -5, 1, -4, 3, -2};
    std::cout << s1.maxAbsoluteSum(nums) << std::endl;
    return 0;
}