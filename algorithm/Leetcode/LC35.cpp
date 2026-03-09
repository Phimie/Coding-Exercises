#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        return find(nums, target);
    }

private:
    int find(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid;
            else
                return mid;
        }
        return left;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    std::cout << s1.searchInsert(nums, target) << std::endl;
    return 0;
}