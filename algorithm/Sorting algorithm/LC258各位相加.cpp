#include <iostream>
#include <cmath>
#include <vector>

class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            if (num == 0)
            {
                return 0;
            }
            int k = (int)log10(num) + 1;
            std::vector<int> nums(k);
            for (int i = 0; i < k; i++)
            {
                nums[i] = (num / (int)pow(10, i)) % 10;
            }
            num = 0;
            for (int i = 0; i < k; i++)
            {
                num += nums[i];
            }
        }
        return num;
    }
};

int main()
{
    Solution s1;
    int num = 12345;
    std::cout << s1.addDigits(num) << std::endl;
    return 0;
}