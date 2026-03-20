#include <iostream>
#include <vector>

class Solution
{
public:
    int maximumPopulation(std::vector<std::vector<int>> &logs)
    {
        int diff[102] = {0};
        for (int i = 0; i < (int)logs.size(); i++)
        {
            diff[logs[i][0] - 1950]++;
            diff[logs[i][1] - 1950]--;
        }
        int sum = 0, maxCount = 0, maxYear = 0;
        for (int i = 0; i < 100; i++)
        {
            sum += diff[i];
            if (sum > maxCount)
            {
                maxCount = sum;
                maxYear = i;
            }
        }
        return maxYear + 1950;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> logs = {{1993, 1999}, {2000, 2010}};
    std::cout << s1.maximumPopulation(logs) << std::endl;
    return 0;
}