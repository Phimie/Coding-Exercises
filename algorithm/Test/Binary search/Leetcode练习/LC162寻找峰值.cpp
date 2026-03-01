#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        int i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (mid == 0)
            {
                return nums[0] > nums[1] ? 0 : 1;
            }
            if (mid == n - 1)
            {
                return nums[n - 1] > nums[n - 2] ? n - 1 : n - 2;
            }

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[mid] < nums[mid + 1])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return i;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    std::cout << s1.findPeakElement(nums) << std::endl;
    return 0;
}