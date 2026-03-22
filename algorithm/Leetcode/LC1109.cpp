#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>> &bookings, int n)
    {
        std::vector<int> diff(n + 2, 0);
        for (int i = 0; i < (int)bookings.size(); i++)
        {
            diff[bookings[i][0]] += bookings[i][2];
            diff[bookings[i][1] + 1] -= bookings[i][2];
        }
        std::vector<int> ans(n, 0);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += diff[i];
            ans[i - 1] = sum;
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    for (int i : s1.corpFlightBookings(bookings, n))
    {
        std::cout << i << ",";
    }

    return 0;
}