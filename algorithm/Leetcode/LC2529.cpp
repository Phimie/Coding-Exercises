#include <vector>

class Solution
{
public:
    int maximumCount(std::vector<int> &nums)
    {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < 0)
                left = mid + 1;
            else
                right = mid;
        }
        int firstzeroidx = left;

        left = 0;
        right = nums.size();
        mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] <= 0)
                left = mid + 1;
            else
                right = mid;
        }
        int secondzeroidx = left;
        return (firstzeroidx > nums.size() - secondzeroidx) ? firstzeroidx : nums.size() - secondzeroidx;
    }
};