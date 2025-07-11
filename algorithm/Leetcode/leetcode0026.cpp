#include <iostream>
#include <vector>
#include <cstring>
#include <string>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        std::vector<int> new_nums(nums.size());
        int index = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] != val)
            {
                new_nums[index] = nums[i];
                index++;
            }
        }
        nums.swap(new_nums);
        return index;
    }
};
int main()
{
    Solution s1;
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    std::cout << s1.removeElement(nums, 2);
    return 0;
}