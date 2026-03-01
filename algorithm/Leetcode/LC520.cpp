#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    bool detectCapitalUse(std::string word)
    {
        if (word.length() == 1)
        {
            return true;
        }
        if (word[0] >= 97 && word[1] < 97)
        {
            return false;
        }
        if (word[0] < 97)
        {
            if (word[1] < 97)
            {
                for (int i = 1; i < word.length(); i++)
                {
                    if (word[i] >= 97)
                    {
                        return false;
                    }
                }
                return true;
            }
            if (word[1] >= 97)
            {
                for (int i = 1; i < word.length(); i++)
                {
                    if (word[i] < 97)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        if (word[0] >= 97)
        {
            for (int i = 1; i < word.length(); i++)
            {
                if (word[i] < 97)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};