#include <iostream>
#include <vector>
#include <unordered_set>
class Solution
{
public:
    int findMaxK(std::vector<int> &nums)
    {
        std::unordered_set<int> freq;
        int maxNum = -1;
        for (int n : nums)
        {
            freq.insert(n);
            if (freq.count(-n))
                maxNum = (maxNum > abs(n)) ? maxNum : abs(n);
        }
        return maxNum;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {-1, 10, 6, 7, -7, 1};
    std::cout << s1.findMaxK(nums) << std::endl;
    return 0;
}