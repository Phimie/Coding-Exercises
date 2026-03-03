#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> freq;
        long long temp_sum = 0 , final_sum = 0;
        int count = 0;

        for (int i = 0; i < (int)nums.size() ; i++){
            freq[nums[i]]++;
            if (freq[nums[i]] == 2) count++;
            temp_sum += nums[i];

            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 1) count--;
                temp_sum -= nums[i - k];
            }

            if (i >= k - 1 && count == 0){
                final_sum = std::max(final_sum, temp_sum);
            }
        }
        return final_sum;
    }
};

int main (){
    Solution s1;
    std::vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    std::cout << s1.maximumSubarraySum(nums,k) << std::endl;
    return 0;
}