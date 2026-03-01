#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
        {
            return nums[nums.size() - 1];
        }
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    i = mid + 2;
                }
                else
                {
                    j = mid;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid;
                }
            }
        }
        return nums[i];
    }
};

int main()
{
    std::vector<int> nums = {-806, -806, -787, -787, -755, -692, -692, -396, -396, -194, -194};
    Solution s1;
    std::cout << s1.singleNumber(nums);
    return 0;
}