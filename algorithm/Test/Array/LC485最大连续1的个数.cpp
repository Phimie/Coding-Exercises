#include <iostream>
#include <vector>

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int result_count = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                if (count > result_count)
                {
                    result_count = count;
                }
                count = 0;
            }
        }
        if (count > result_count)
        {
            result_count = count;
        }
        return result_count;
    }
};