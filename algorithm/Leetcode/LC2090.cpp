#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> avgs(n, -1);
        if (2 * k + 1 > n) return avgs;
        long long sum = 0;
        for (int i = 0 ; i < k*2+1 ; i++){
            sum += nums[i];
        }
        avgs[k] = sum/(2*k+1);
        for (int i = k + 1 ; i < n-k ; i++){
            sum -= nums[i - k - 1];
            sum += nums[i + k];
            avgs[i] = sum/(2*k+1);
        }
        return avgs;
    }
};

int main(){
    Solution S1;
    std::vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    std::vector<int> result = S1.getAverages(nums, k);
    for (int i = 0 ; i < (int)result.size() ; i++){
        std::cout << result[i] << ",";
    }
    return 0;
}