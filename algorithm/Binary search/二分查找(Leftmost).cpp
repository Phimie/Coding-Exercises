#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int binarySearch(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        int candidate = -1; // 候选mid
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
                // 记录候选位置
                candidate = mid;
                j = mid;
            }
        }
        return candidate;
    }
};
int main()
{
    std::vector<int> nums = {0, 1, 3, 3, 4, 5};

    Solution s1;
    int target = 3;
    std::cout << s1.binarySearch(nums, target);
    return 0;
}