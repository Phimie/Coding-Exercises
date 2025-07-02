#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int singleNonDuplicate(std::vector<int> &nums)
    {
        std::vector<int> new_nums1(nums.size() / 2 + 1);
        std::vector<int> new_nums2(nums.size() / 2 + 1);
        for (int i = 0, j = 0; i < nums.size(); i += 2, j++)
        {
            new_nums1[j] = nums[i]; //{1,2,3,4,8}
        }
        for (int i = 1, j = 0; i < nums.size(); i += 2, j++)
        {
            new_nums2[j] = nums[i]; //{1,3,4,8}
        }
        for (int i = 0; i < new_nums2.size(); i++)
        {
            if (new_nums1[i] != new_nums2[i])
            {
                return new_nums1[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << s1.singleNonDuplicate(nums);
    return 0;
}