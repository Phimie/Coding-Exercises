#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool backspaceCompare(std::string s, std::string t)
    {
        return Func(s) == Func(t);
    }
    std::string Func(std::string str)
    {
        std::vector<char> stk;
        for (char c : str)
        {
            if (c != '#')
                stk.push_back(c);
            else if (!stk.empty())
                stk.pop_back();
        }
        return std::string(stk.begin(), stk.end());
    }
};

int main()
{
    Solution s1;
    std::string s = "ab#c";
    std::string t = "ad#c";
    std::cout << s1.backspaceCompare(s, t) << std::endl;
    return 0;
}