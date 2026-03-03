#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::unordered_map<char, int> freq;
        int left = 0, max_len = 0;
        for (int right = 0 ; right < (int)s.size() ; right++){
            if (freq.count(s[right]) && right > left) {
                freq[s[right]]++;
                if (freq[s[right]] == 2) {
                    max_len = (max_len < right - left + 1) ? right - left + 1 : max_len;
                }else{
                    freq[s[left]]--;
                    left++;
                }
            }else{
                freq.insert({s[right],1});
            }
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