#include <iostream>
#include <vector>
class InsertionSort
{
public:
    std::vector<int> sort(std::vector<int> nums)
    {
    }

private:
    std::vector<int> f(std::vector<int> nums, int low)
    {
        if (low == nums.size())
        {
            return nums;
        }
        return f(nums, low + 1); // 写return的作用:向上传递nums副本
    }
};

int main()
{
    return 0;
}
