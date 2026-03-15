#include <iostream>
#include <vector>

class NumArray
{
public:
    std::vector<int> prefix;
    NumArray(std::vector<int> &nums)
    {
        int n = nums.size();
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }
};

int main()
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    std::cout << "sumRange(0, 2) = " << numArray.sumRange(0, 2);
    return 0;
}