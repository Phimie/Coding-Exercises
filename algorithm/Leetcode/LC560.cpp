#include <iostream>
#include <vector>
/*
class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        std::vector<int> prefix((int)nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 1, 1};
    int k = 2;
    std::cout << s1.subarraySum(nums, k) << std::endl;
    return 0;
}
*/