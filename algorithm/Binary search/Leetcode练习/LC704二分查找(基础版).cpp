/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。
你必须编写一个具有 O(log n) 时间复杂度的算法。
*/

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
            int mid = (i + j) / 2;
            if (target < nums[mid]) // 当target为最左侧元素时,判断次数为L
            {
                j = mid - 1;
            }
            else if (nums[mid] < target) // 当target为最右侧元素时,判断次数为2 * L; (不平衡)
            {
                i = mid + 1;
            }
            else
            {
                return mid; // 最优情况为,target刚好为中间元素,即O(1);
            }
        }
        return -1;
    }
};

int main()
{
    int target = 5;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution s1;
    std::cout << s1.search(nums, target);
    return 0;
}