#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0, left = 0;
        for (int right = 0; right < s.size() ; right++){
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'u' || s[right] == 'o'){
                vowel++;
            }
            if (right - left >= k){
                if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'u' || s[left] == 'o'){
                    vowel--;
                }
                left++;
            }
            ans = (ans > vowel) ? ans : vowel;
            if (vowel == k) return k;  // 如果vowel已经达到理论最大值可提前退出
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s1 = "abciiidef";
    int k1 = 3;
    cout << solution.maxVowels(s1, k1) << endl;
    return 0;
}