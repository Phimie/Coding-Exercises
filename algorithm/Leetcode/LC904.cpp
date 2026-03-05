#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int maxLen = 0, left = 0;
        std::unordered_map<int, int> freq;
        for (int i = 0 ; i < (int)fruits.size() ; i++){
            freq[fruits[i]]++;

            while(freq.size() > 2){
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }
            
            maxLen = std::max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};

int main () {
    Solution s1;
    std::vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    std::cout << s1.totalFruit(fruits) << std::endl;
    return 0;
}