#include <iostream>
#include <vector>

class Solution
{
public:
    bool isCovered(std::vector<std::vector<int>> &ranges, int left, int right)
    {
        int diff[52] = {0};
        for (std::vector range : ranges)
        {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        int sum = 0;
        for (int i = 1; i <= 50; i++)
        {
            sum += diff[i];
            if (i >= left && i <= right && sum <= 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
    int left = 2, right = 5;
    std::cout << s1.isCovered(ranges, left, right) << std::endl;
    return 0;
}