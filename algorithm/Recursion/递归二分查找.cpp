#include <iostream>
#include <vector>
class BinarySearch
{
public:
    int search(std::vector<int> nums, int target)
    {

        return f(nums, target, 0, nums.size() - 1);
    }

private:
    int f(std::vector<int> nums, int target, int i, int j)
    {
        if (i > j)
        {
            return -1;
        }
        int m = i + ((j - i) >> 1);
        if (target < nums[m])
        {
            return f(nums, target, i, m - 1);
        }
        else if (nums[m] < target)
        {
            return f(nums, target, m + 1, j);
        }
        else
        {
            return m;
        }
    }
};

int main()
{
    std::vector<int> nums = {7, 13, 21, 30, 38, 44, 52, 53};
    BinarySearch b1;
    std::cout << b1.search(nums, 38);
    return 0;
}