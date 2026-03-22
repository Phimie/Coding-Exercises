#include <iostream>
#include <vector>

class Solution
{
public:
    bool isZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> diff(nums.size() + 2, 0);
        for (int i = 0; i < (int)queries.size(); i++)
        {
            diff[queries[i][0]]++;
            diff[queries[i][1] + 1]--;
        }
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            sum += diff[i];
            if (nums[i] > sum)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {7};
    std::vector<std::vector<int>> queries = {{0, 0}};
    std::cout << s1.isZeroArray(nums, queries) << std::endl;
    return 0;
}