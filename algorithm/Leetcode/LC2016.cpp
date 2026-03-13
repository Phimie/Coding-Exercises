#include <vector>
using namespace std;
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int minNum = INT_MAX;
        int ans = -1;
        for (int n : nums)
        {
            if (n > minNum)
            {
                ans = max(ans, n - minNum);
            }
            minNum = min(minNum, n);
        }
        return ans;
    }
};