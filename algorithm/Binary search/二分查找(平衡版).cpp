// 1.左闭右开的区间,i指向的可能是目标,而j指向的不是目标
// 2.不在循环内找出,等范围内只剩i时,退出循环,在循环外比较 a[i] 与target
// 3.循环的平均比较次数减少了
// 4.最好最坏情况都是O(log(n))

#include <vector>
#include <iostream>

class Solution
{
public:
    int binarySearch(std::vector<int> nums, int target)
    {
        int i = 0, j = nums.size();
        while (1 < j - i)
        {
            int mid = i + ((j - i) >> 1);
            if (target < nums[mid]) // 只判断一次条件 (平衡)
            {
                j = mid;
            }
            else
            {
                i = mid; // i可能指向的是目标
            }
        }
        if (nums[i] == target)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 8;
    Solution s1;
    std::cout << s1.binarySearch(nums, target);
    return 0;
}
