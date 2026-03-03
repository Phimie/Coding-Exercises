#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    long long maxSum(std::vector<int>& nums, int m, int k) {
        long long temp_sum = 0,final_sum = 0;
        int count = 0;
        std::unordered_map<int,int> freq;
        for (int i = 0 ; i < (int)nums.size() ; i++){
            temp_sum += nums[i];
            if (++freq[nums[i]] == 1) count++;
            if (i >= k){
                if (--freq[nums[i - k]] == 0) count--;
                temp_sum -= nums[i - k];
            }
            if (i >= k - 1 && count >= m) final_sum = std::max(temp_sum,final_sum);
        }
        return final_sum;
    }
};

int main (){
    Solution s1;
    std::vector<int> nums = {2,6,7,3,1,7};
    int m = 3,k = 4;
    std::cout << s1.maxSum(nums,m,k) << std::endl;
    return 0;
}