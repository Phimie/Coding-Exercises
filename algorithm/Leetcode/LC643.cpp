#include <iostream>
#include <vector>
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }
        double ans = sum;
        for (size_t right = k; right < nums.size() ; right++){
            sum+=nums[right];
            sum-=nums[right-k];
            ans = (ans < sum) ? sum : ans;
        }
        return ans/k;
    }
};

int main(){
    Solution s1;
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    std::cout << s1.findMaxAverage(nums,k) << std::endl;
    return 0;
}