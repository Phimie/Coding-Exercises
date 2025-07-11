#include <iostream>
#include <string>
#include <cstring>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string s = std::to_string(x);
        int s_size = s.size();
        char cs[s_size] = {0};
        for (int i = 0; i < s_size; i++) // 转换成字符数组
        {
            cs[i] = s[i];
        }
        char r[s_size];
        for (int i = 0; i < s_size; i++) // 复制一份待翻转的数组
        {
            r[i] = cs[i];
        }
        for (int i = 0, j = s_size - 1; i < j; i++, j--) // 翻转r[]
        {
            char c = r[i];
            r[i] = r[j];
            r[j] = c;
        }
        for (int i = 0; i < s_size; i++)
        {
            if (r[i] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int x = 101;
    Solution s1;
    if (s1.isPalindrome(x) == true)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }

    return 0;
}