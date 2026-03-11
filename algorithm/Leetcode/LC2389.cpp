#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> answerQueries(std::vector<int> &nums, std::vector<int> &queries)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> ans = {};
        int numsCount = 0, count = 0;
        for (int i = 0; i < (int)queries.size(); i++)
        {
            numsCount = 0;
            count = 0;
            for (int j = 0; j < (int)nums.size(); j++)
            {
                numsCount += nums[j];
                if (numsCount <= queries[i])
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {4, 5, 2, 1};
    std::vector<int> queries = {3, 10, 21};
    std::vector<int> ans = s1.answerQueries(nums, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}