#include <vector>
class Solution
{
public:
    int maximumSum(std::vector<int> &nums)
    {
        int ans = -1;
        std::vector<int> max(82, INT_MIN);
        for (int num : nums)
        {
            int s = 0;
            for (int x = num; x; x /= 10)
            {
                s += x % 10;
            }
            ans = std::max(ans, max[s] + num);
            max[s] = std::max(max[s], num);
        }
        return ans;
    }
};