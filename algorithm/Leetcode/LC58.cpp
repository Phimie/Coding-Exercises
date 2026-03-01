#include <string>
#include <iostream>
#include <vector>
class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int s_size = static_cast<int>(s.size());
        std::vector<char> new_s(s_size);
        int index = 0;
        for (int i = s_size - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (index > 0)
                {
                    break;
                }
            }
            else
            {
                new_s.push_back(s[i]);
                index++;
            }
        }
        return index;
    }
};

int main()
{
    Solution s1;
    std::cout << s1.lengthOfLastWord("Hello World");
    return 0;
}