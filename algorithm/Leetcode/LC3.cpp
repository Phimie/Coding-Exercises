#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> hashmap;
        int left = 0, max_size = 0;

        for (int right = 0 ; right < (int)s.size(); right++){
            if (hashmap.count(s[right]) && hashmap[s[right]] >= left){
                left = hashmap[s[right]] + 1;
            }
            hashmap[s[right]] = right;
            max_size = (max_size < right - left + 1)?right - left + 1 : max_size;
        }

        return max_size;
    }
};

int main (){
    Solution s1;
    std::string s = "abcabcbb";
    std::cout << s1.lengthOfLongestSubstring(s) << std::endl;
    return 0;
}