#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            if (target < nums[mid])
            {
                j = mid - 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                int m = mid, n = mid;
                while (m >= 0 && nums[m] == target)
                {
                    m--;
                }
                while (n < nums.size() && nums[n] == target)
                {
                    n++;
                }
                return {m + 1, n - 1};
            }
        }

        return {-1, -1};
    }
};
int main()
{
    Solution s1;
    std::vector<int> nums = {5, 5, 7, 7, 8, 8, 10};
    int target = 8;
    std::vector<int> result = s1.searchRange(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ",";
    }
    return 0;
}