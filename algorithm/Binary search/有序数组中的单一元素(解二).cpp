#include <iostream>
#include <vector>

class Solution
{
public:
    int singleNonDuplicate(std::vector<int> &nums)
    {
        int i = 0;
        int m = nums.size() - 1;

        while (i < m)
        {
            int mid = i + (m - i) / 2;

            if (mid % 2 == 1)
            {
                mid--;
            }

            if (nums[mid] == nums[mid + 1])
            {
                i = mid + 2;
            }
            else
            {
                m = mid;
            }
        }

        return nums[i];
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << s1.singleNonDuplicate(nums) << std::endl;
    return 0;
}