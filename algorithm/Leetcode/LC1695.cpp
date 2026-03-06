#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maximumUniqueSubarray(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freq;
        int left = 0, tempSum = 0, finalSum = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            freq[nums[i]]++;
            tempSum += nums[i];
            while (freq[nums[i]] >= 2)
            {
                tempSum -= nums[left];
                freq[nums[left]]--;
                left++;
            }
            finalSum = std::max(finalSum, tempSum);
        }
        return finalSum;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    std::cout << s1.maximumUniqueSubarray(nums) << std::endl;
    return 0;
}