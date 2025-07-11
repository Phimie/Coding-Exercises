#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        if (digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1]++;
            return digits;
        }
        else
        {
            for (int i = digits.size() - 1; i >= 0; i--)
            {
                if (digits[i] == 9)
                {
                    digits[i] = 0;
                    continue;
                }
                else
                {
                    digits[i]++;
                    return digits;
                }
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    std::vector<int> digits = {9, 9, 9};

    Solution s1;
    s1.plusOne(digits);

    for (int i = 0; i < digits.size(); i++)
    {
        std::cout << digits[i] << ",";
    }

    return 0;
}