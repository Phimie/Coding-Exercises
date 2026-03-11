#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int findTheDistanceValue(std::vector<int> &arr1, std::vector<int> &arr2, int d)
    {
        std::sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int i = 0; i < (int)arr1.size(); i++)
        {
            int x = arr1[i];
            int left = 0, right = (int)arr2.size();
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (arr2[mid] < x - d)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (left == (int)arr2.size() || arr2[left] > x + d)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s1;
    std::vector<int> arr1 = {4, 5, 8};
    std::vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    std::cout << s1.findTheDistanceValue(arr1, arr2, d) << std::endl;
    return 0;
}