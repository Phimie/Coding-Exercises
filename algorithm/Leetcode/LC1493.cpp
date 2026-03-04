#include <iostream>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int max_len = 0,count = 0,left = 0;
        for (int i = 0; i < (int)nums.size() ; i++){
            if (nums[i] == 0) count++;
            while (count > 1) {
                if (nums[left] == 0) count--;
                left++;
            }
            max_len = std::max(max_len,i - left);
        }
        return max_len;
    }
};

int main (){
    Solution s1;
    std::vector<int> nums = {1};
    std::cout << s1.longestSubarray(nums) << std::endl;
    return 0;
}