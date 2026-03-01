#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int heightChecker(std::vector<int> &heights)
    {
        std::vector<int> oHeights = heights;
        sort(heights.begin(), heights.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != oHeights[i])
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    std::vector<int> nums = {1, 1, 4, 2, 1, 3};
    Solution s1;
    std::cout << s1.heightChecker(nums);
    return 0;
}