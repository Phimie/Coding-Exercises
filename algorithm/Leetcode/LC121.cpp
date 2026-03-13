
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minNum = prices[0], ans = 0;
        for (int p : prices)
        {
            ans = max(ans, p - minNum);
            minNum = min(minNum, p);
        }
        return ans;
    }
};