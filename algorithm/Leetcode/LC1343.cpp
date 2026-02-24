#include <vector>
#include <iostream>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int m = threshold * k;
        for (int i = 0; i < k; i++){
            sum += arr[i];
        }
        int ans = (sum >= m) ? 1 : 0; 
        for (int i = k; i < (int)arr.size(); i++){
            sum += arr[i];
            sum -= arr[i - k];
            if (sum >= m){
                ans++;
            }
        }
        return ans;
    }
};

int main (){
    Solution s1;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3, threshold = 4;
    std::cout << s1.numOfSubarrays(arr,k,threshold) << std::endl;
    return 0;
}