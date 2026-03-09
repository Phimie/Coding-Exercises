#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBound = lowerBound(nums, target);
        if (leftBound == nums.size() || nums[leftBound] != target)
            return {-1, -1};
        int rightBound = lowerBound(nums, target + 1) - 1;
        return {leftBound, rightBound};
    }

private:
    int lowerBound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};