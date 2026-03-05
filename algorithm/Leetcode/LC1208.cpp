#include <iostream>
#include <string>
class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int n = s.size();
        int maxLen = 0;
        int tempCost = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            tempCost += abs(s[right] - t[right]);
            while (tempCost > maxCost) {
                tempCost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main () {
    Solution s1;
    std::string s = "krrgw";
    std::string t = "zjxss";
    int maxCost = 19;
    std::cout << s1.equalSubstring(s,t,maxCost) << std::endl;
    return 0;
}