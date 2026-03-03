#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::unordered_map<char, int> freq;
        int left = 0, max_len = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            freq[s[right]]++;
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main (){
    Solution s1;
    std::string s = "bcbbbcba";
    std::cout << s1.maximumLengthSubstring(s) << std::endl;
    return 0;
}