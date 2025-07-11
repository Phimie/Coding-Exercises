#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        std::string result = "";
        int index = 0;

        while (true)
        {
            if (index >= static_cast<int>(strs[0].size()))
            {
                break;
            }

            char current_char = strs[0][index];

            for (int i = 1; i < static_cast<int>(strs.size()); i++)
            {
                if (index >= static_cast<int>(strs[i].size()) || strs[i][index] != current_char)
                {
                    return result;
                }
            }

            result += current_char;
            index++;
        }

        return result;
    }
};

int main()
{
    Solution s1;
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << s1.longestCommonPrefix(strs1) << std::endl;

    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << s1.longestCommonPrefix(strs2) << std::endl;

    std::vector<std::string> strs3 = {"a"};
    std::cout << s1.longestCommonPrefix(strs3) << std::endl;

    return 0;
}