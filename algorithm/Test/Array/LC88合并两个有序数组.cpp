#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            nums1[m + i] = nums2[i];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = static_cast<int>(nums1.size()), n = (int)nums2.size();
    s1.merge(nums1, m, nums2, n);
    return 0;
}