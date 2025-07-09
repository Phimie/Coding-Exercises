#include <iostream>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return;
        }
        int count0 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == 0)
            {
                bool found = false;
                for (int k = i + 1; k < n; k++)
                {
                    if (nums[k] != 0)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    break;
                }
                for (int j = i + 1; j < n; j++)
                {
                    nums[j - 1] = nums[j];
                }
                count0++;
                i--;

                if (count0 > n)
                {
                    break;
                }
            }
        }
        for (int i = n - count0; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};