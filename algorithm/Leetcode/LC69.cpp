#include <iostream>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        for (long long i = 1; i <= x; ++i)
        {
            if (i * i == x)
            {
                return static_cast<int>(i);
            }
            else if (i * i > x)
            {
                return static_cast<int>(i - 1);
            }
        }
        return -1;
    }
};