#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int binarySearch(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        while (i < j)
        {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else if (nums[mid] > target)
            {
                j = mid;
            }
            else
            {
                return mid;
            }
        }
        return -(i + 1); // not found ,return: -index - i
    }
};

int main()
{
    std::vector<int> nums = {0, 1, 3, 4, 5};

    Solution s1;
    int target = 2;
    int k = s1.binarySearch(nums, target);
    std::cout << k << std::endl;
    // 插入值
    if (k < 0)
    {
        int insertIndex = -(k + 1); // 插入点索引
        std::vector<int> nums2(nums.size() + 1);
        for (int i = 0; i < insertIndex; i++)
        {
            nums2[i] = nums[i];
        }
        nums2[insertIndex] = target;
        for (int i = insertIndex + 1; i < nums2.size(); i++)
        {
            nums2[i] = nums[i - 1];
        }
        // 输出nums2
        for (int i = 0; i < nums2.size(); i++)
        {
            std::cout << nums2[i] << ",";
        }
    }
    return 0;
}