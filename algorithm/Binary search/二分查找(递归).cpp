#include <iostream>
#include <vector>
int binarySerch(std::vector<int> nums, int target, int i, int j)
{
    if (i > j)
    {
        return -1;
    }

    int mid = i + ((j - i) >> 1);
    if (target < nums[mid])
    {
        return binarySerch(nums, target, i, mid - 1);
    }
    else if (nums[mid] < target)
    {
        return binarySerch(nums, target, mid + 1, j);
    }
    else
    {
        return mid;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    int target = 1;
    std::cout << binarySerch(nums, target, 0, nums.size() - 1);
    return 0;
}