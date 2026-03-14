#include <vector>
#include <iostream>
class Solution
{
public:
    int maxDistance(std::vector<std::vector<int>> &arrays)
    {
        int ans = 0;
        int min = INT_MAX / 2, max = INT_MIN / 2;
        for (std::vector<int> a : arrays)
        {
            ans = std::max({ans, a.back() - min, max - a[0]});
            min = std::min(min, a[0]);
            max = std::max(max, a.back());
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> arrays = {{1, 4}, {0, 5}};
    std::cout << s1.maxDistance(arrays) << std::endl;
    return 0;
}