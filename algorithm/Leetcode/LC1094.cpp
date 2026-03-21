#include <iostream>
#include <vector>

class Solution
{
public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
    {
        int diff[1002] = {0};
        for (int i = 0; i < trips.size(); i++)
        {
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];
        }
        int sum = 0;
        for (int i = 0; i < 1001; i++)
        {
            sum += diff[i];
            if (sum > capacity)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;
    std::cout << s1.carPooling(trips, capacity) << std::endl;
}