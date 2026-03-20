#include <iostream>
#include <vector>

class Solution
{
public:
    int maxAliveYear(std::vector<int> &birth, std::vector<int> &death)
    {
        int diff[102] = {0};
        for (int i = 0; i < (int)birth.size(); i++)
        {
            diff[birth[i] - 1900]++;
            diff[death[i] - 1900 + 1]--;
        }
        int sum = 0, maxCount = 0, maxYear = 0;
        for (int i = 0; i <= 100; i++)
        {
            sum += diff[i];
            if (sum > maxCount)
            {
                maxCount = sum;
                maxYear = i;
            }
        }
        return maxYear + 1900;
    }
};

int main()
{
    Solution s1;
    std::vector<int> birth = {1900, 1901, 1950};
    std::vector<int> death = {1948, 1951, 2000};
    std::cout << s1.maxAliveYear(birth, death);
    return 0;
}