#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            if (target == nums[i])
            {
                return i;
            }
            else if (target == nums[j])
            {
                return j;
            }
        }
        return -1;
    }
};

int main()
{
    int target = 5;
    std::vector<int> nums = {3, 9, 1, 6, 4, 5, 13, 45, 23, 12, 87, 65, 34, 98, 44, 2, 34};
    Solution s1;
    std::cout << s1.search(nums, target);
    return 0;
}