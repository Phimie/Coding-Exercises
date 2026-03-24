#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::string removeStars(std::string s)
    {
        std::string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
            {
                ans.pop_back();
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::string s = "leet**cod*e";
    std::cout << s1.removeStars(s) << std::endl;
    return 0;
}