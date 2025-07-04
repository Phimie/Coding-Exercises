#include <iostream>
#include <string>
#include <vector>

const int pickedNumber = 42;

int guess(int num)
{
    if (num > pickedNumber)
    {
        return -1;
    }
    else if (num < pickedNumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int i = 1, j = n;
        while (i <= j)
        {
            int mid = i + (j - i) / 2; // i + (j - i) / 2 这个算式避免了i+j的溢出问题
            // int m = i + ((j - i) >> 1); 右移运算符也可以解决
            if (guess(mid) == -1)
            {
                j = mid - 1;
            }
            else if (guess(mid) == 1)
            {
                i = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s1;
    int n = 100;
    std::cout << s1.guessNumber(n);
    return 0;
}