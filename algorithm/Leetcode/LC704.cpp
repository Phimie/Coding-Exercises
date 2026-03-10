#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};