#include <vector>
#include <algorithm>
class Solution
{
public:
    std::vector<int> successfulPairs(std::vector<int> &spells, std::vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        std::vector<int> result;
        for (int idx = 0; idx < spells.size(); idx++)
        {
            int i = 0, j = potions.size();
            int res = -1;
            while (i < j)
            {
                int mid = i + ((j - i) >> 1);
                if (1LL * spells[idx] * potions[mid] >= success)
                {
                    j = mid;
                    res = mid;
                }
                else
                {
                    i = mid + 1;
                }
            }
            if (res >= 0)
            {
                result.push_back(potions.size() - res);
            }
            else
            {
                result.push_back(0);
            }
        }
        return result;
    }
};
