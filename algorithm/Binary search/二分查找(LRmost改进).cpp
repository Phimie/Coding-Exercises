#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    // Leftmost(返回值改进)
    int binarySearchLeftmost(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        while (i < j)
        {
            int mid = i + ((j - i) >> 1);
            if (target <= nums[mid])
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i; // return: 返回 >= target 的最靠左索引;
    }

    // Rightmost(返回值改进)
    int binarySearchRightmost(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        while (i < j)
        {
            int mid = i + ((j - i) >> 1);
            if (target >= nums[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return i - 1; // return: 返回 <= target 的最靠右索引;
    }
};
int main()
{
    std::vector<int> nums = {0, 1, 3, 3, 3, 3, 3, 3, 4, 5};

    Solution s1;
    int target = 2;
    std::cout << s1.binarySearchLeftmost(nums, target) << std::endl;
    std::cout << s1.binarySearchRightmost(nums, target) << std::endl;
    return 0;
}