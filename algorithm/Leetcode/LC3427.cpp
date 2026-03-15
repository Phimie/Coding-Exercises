#include <iostream>
#include <vector>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        // 初始化前缀和
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int start = 0, ans = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            start = std::max(0, i - nums[i]);
            ans += prefix[i + 1] - prefix[start];
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {2, 3, 1};
    std::cout << s1.subarraySum(nums) << std::endl;
    return 0;
}