#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxSubarrayLength(std::vector<int> &nums, int k)
    {
        int maxLen = 0, left = 0;
        std::unordered_map<int, int> freq;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            freq[nums[i]]++;
            while (freq[nums[i]] > k)
            {
                freq[nums[left]]--;
                left++;
            }
            maxLen = std::max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {5, 5, 5, 5, 5, 5, 5};
    int k = 4;
    std::cout << s1.maxSubarrayLength(nums, k) << std::endl;
    return 0;
}