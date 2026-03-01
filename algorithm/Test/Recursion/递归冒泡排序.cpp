#include <iostream>
#include <vector>
class BubbleSort
{
public:
    std::vector<int> sort(std::vector<int> nums)
    {
        return f(nums, nums.size() - 1);
    }

private:
    std::vector<int> f(std::vector<int> nums, int j)
    {
        if (j == 0)
        {
            return nums;
        }
        int x = 0; // 递归冒泡排序优化点
        for (int i = 0; i < j; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                int t = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = t;
                x = i;
            }
        }
        return f(nums, x); // 写return的作用:向上传递nums副本
    }
};

int main()
{
    std::vector<int> nums = {2, 4, 67, 3, 1, 2, 0, 9, 8, 6, 5, 3, 345, 6, 567};
    BubbleSort b1;
    nums = b1.sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << ",";
    }
    return 0;
}