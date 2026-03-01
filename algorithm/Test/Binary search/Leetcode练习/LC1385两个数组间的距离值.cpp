#include <vector>
#include <algorithm>
class Solution
{
public:
    int findTheDistanceValue(std::vector<int> &arr1, std::vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int result = 0;
        for (int idx = 0; idx < arr1.size(); idx++)
        {
            bool find = true;
            int i = 0, j = arr2.size();
            while (i < j)
            {
                int mid = i + ((j - i) >> 1);
                if (arr2[mid] > arr1[idx] + d)
                {
                    j = mid;
                }
                else if (arr2[mid] < arr1[idx] - d)
                {
                    i = mid + 1;
                }
                else
                {
                    find = false;
                    break;
                }
            }
            if (find)
            {
                result++;
            }
        }
        return result;
    }
};