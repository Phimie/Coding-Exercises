#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<bool> isArraySpecial(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> prefix(nums.size(), 0);
        for (int i = 1; i < (int)nums.size(); i++)
        {
            if ((nums[i] % 2) == (nums[i - 1] % 2))
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1];
        }
        std::vector<bool> ans(queries.size(), 0);
        for (int i = 0; i < (int)queries.size(); i++)
        {
            if (prefix[queries[i][1]] - prefix[queries[i][0]] == 0)
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {4, 3, 1, 6};
    std::vector<std::vector<int>> queries = {{0, 2}, {2, 3}};
    for (int b : s1.isArraySpecial(nums, queries))
    {
        std::cout << b << ',';
    }
    return 0;
}
