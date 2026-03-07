#include <iostream>
#include <vector>

class Solution
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        int left = 0, finalLen = 0, count = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] == 0)
                count++;

            while (count > k)
            {
                if (nums[left] == 0)
                    count--;
                left++;
            }

            finalLen = std::max(finalLen, i - left + 1);
        }
        return finalLen;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    std::cout << s1.longestOnes(nums, k) << std::endl;
    return 0;
}