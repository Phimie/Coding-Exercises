#include <vector>
#include <iostream>

class Solution
{
public:
    int maximumCount(std::vector<int> &nums)
    {
        int neg = 0, pos = 0;
        int i = 0, j = nums.size();

        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] < 0)
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        neg = i;

        i = 0, j = nums.size();
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= 0)
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        pos = nums.size() - i;

        return (pos > neg) ? pos : neg;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {-2, -1, -1, 0, 1, 2, 3};
    std::cout << s1.maximumCount(nums) << std::endl;
    return 0;
}