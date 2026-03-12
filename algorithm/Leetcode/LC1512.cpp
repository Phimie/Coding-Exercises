#include <iostream>
#include <vector>
#include <unordered_map>
class Solution
{
public:
    int numIdenticalPairs(std::vector<int> &nums)
    {
        int ans = 0;
        std::unordered_map<int, int> freq;
        for (int i : nums)
        {
            ans += freq[i];
            freq[i]++;
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> nums = {1, 2, 3, 1, 1, 3};
    std::cout << s1.numIdenticalPairs(nums) << std::endl;
    return 0;
}