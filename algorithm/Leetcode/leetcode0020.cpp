#include <iostream>
#include <string>
#include <cstring>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::vector<char> left;

        for (char c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                left.push_back(c);
            }
            else if (c == '}' || c == ']' || c == ')')
            {
                if (left.empty())
                {
                    return false;
                }
                char right = left.back();
                left.pop_back();
                if ((c == '}' && right != '{') ||
                    (c == ']' && right != '[') ||
                    (c == ')' && right != '('))
                {
                    return false;
                }
            }
        }

        return left.empty();
    }
};