#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int thirdMax(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        
    }
};

int main()
{
    std::vector<int> nums = {2, 2, 3, 1};
    Solution s1;
    std::cout << s1.thirdMax(nums);
    return 0;
}