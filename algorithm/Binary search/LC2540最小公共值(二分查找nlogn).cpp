#include <vector>
#include <iostream>

class Solution
{
public:
    int getCommon(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        for (int tIdx = 0; tIdx < nums1.size(); tIdx++)
        {
            int i = 0, j = nums2.size();
            while (i < j)
            {
                int mid = i + ((j - i) >> 1);
                if (nums2[mid] < nums1[tIdx])
                {
                    i = mid + 1;
                }
                else if (nums2[mid] > nums1[tIdx])
                {
                    j = mid;
                }
                else
                {
                    return nums2[mid];
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums1 = {1, 2, 3, 6}, nums2 = {2, 3, 4, 5};
    std::cout << s1.getCommon(nums1, nums2);
    return 0;
}
