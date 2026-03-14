#include <vector>
#include <iostream>
class Solution
{
public:
    int maxDistance(std::vector<std::vector<int>> &arrays)
    {
        int maxDistance = -1, minNum = INT_MAX, i = 0;
        for (std::vector<int> array : arrays)
        {
            for (int num : array)
            {
                minNum = std::min(minNum, num);
                maxDistance = std::max(maxDistance, abs(num - minNum));
            }
        }
        return maxDistance;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> arrays = {{1, 4}, {0, 5}};
    std::cout << s1.maxDistance(arrays) << std::endl;
    return 0;
}