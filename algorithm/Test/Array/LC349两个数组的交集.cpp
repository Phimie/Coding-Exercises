#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> result;
        for (int k = 0; k < nums1.size(); k++)
        {
            if (k > 0 && nums1[k] == nums1[k - 1])
                continue;
            int target = nums1[k];
            int i = 0, j = nums2.size();

            while (i < j)
            {
                int mid = i + (j - i) / 2;
                if (nums2[mid] < target)
                {
                    i = mid + 1;
                }
                else if (nums2[mid] > target)
                {
                    j = mid;
                }
                else
                {
                    result.push_back(target);
                    break;
                }
            }
        }
        return result;
    }
};