#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> targetIndices(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;

        int i = 0, j = nums.size() - 1;
        int pos1 = -1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                pos1 = mid;
                j = mid - 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        if (pos1 == -1)
        {
            return res;
        }

        i = pos1, j = nums.size() - 1;
        int pos2 = pos1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                pos2 = mid;
                i = mid + 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        for (int k = pos1; k <= pos2; ++k)
        {
            res.push_back(k);
        }

        return res;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 2, 5, 2, 3};
    std::vector<int> result = s1.targetIndices(nums, 5);

    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << ",";
    }
    return 0;
}