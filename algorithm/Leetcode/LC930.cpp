/*
#include <iostream>
#include <vector>

class Solution
{
public:
    int numSubarraysWithSum(std::vector<int> &nums, int goal)
    {
        std::vector<int> prefix(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    std::cout << s1.numSubarraysWithSum(nums, goal) << std::endl;
    return 0;
}
*/