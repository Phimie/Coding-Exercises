#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            int cur = a + b;
            a = b;
            b = cur;
        }
        return b;
    }
};