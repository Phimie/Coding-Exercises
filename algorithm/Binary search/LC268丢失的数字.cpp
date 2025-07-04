// 排序后二分

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] == mid)
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        if (j == nums.size() - 1 && nums[j] == j)
        {
            return j + 1;
        }
        return j;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {3, 0, 1};
    std::cout << s1.missingNumber(nums);
    return 0;
}