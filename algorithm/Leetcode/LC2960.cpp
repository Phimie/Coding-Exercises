#include <iostream>
#include <vector>

class Solution
{
public:
    int countTestedDevices(std::vector<int> &batteryPercentages)
    {
        int dec = 0;
        for (int x : batteryPercentages)
        {
            dec += x > dec;
        }
        return dec;
    }
};

int main()
{
    Solution s1;
    std::vector<int> batteryPercantages = {1, 1, 2, 1, 3};
    std::cout << s1.countTestedDevices(batteryPercantages) << std::endl;
    return 0;
}