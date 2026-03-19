#include <iostream>
#include <vector>

class Solution
{
public:
    int numberOfPoints(std::vector<std::vector<int>> &nums)
    {
        int diff[102] = {};
        for (std::vector<int> car : nums)
        {
            diff[car[0]]++;
            diff[car[1] + 1]--;
        }
        int count = 0, sum = 0;
        for (int i = 1; i < 100; i++)
        {
            sum += diff[i];
            if (sum > 0)
                count++;
        }
        return count;
    }
};
int main()
{
    Solution s1;
    std::vector<std::vector<int>> nums = {{3, 6}, {1, 5}, {4, 7}};
    std::cout << s1.numberOfPoints(nums) << std::endl;
    return 0;
}