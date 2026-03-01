#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    std::vector<int> result = {i, j};
                    return result;
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 3, 5, 8, 2};
    int target = 10;
    std::vector<int> result = s1.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ",";
    }

    return 0;
}
