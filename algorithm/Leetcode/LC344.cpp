#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        char temp = ' ';
        for (int i = 0, j = s.size() - 1; i < s.size() / 2 && j >= s.size() / 2; i++, j--)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};