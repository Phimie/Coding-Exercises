#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minRemoval(std::vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxLen = 0, left = 0;
        for (int i = 0; i < n; i++){
            while (nums[i] > (long long)k * nums[left]){
                left++;
            }
            maxLen = std::max(maxLen, i - left + 1);
        }
        return n - maxLen;
    }
};

int main (){
    Solution s1;
    std::vector<int> nums = {2,1,5};
    int k = 2;
    std::cout << s1.minRemoval(nums, k) << std::endl;
    return 0;
}