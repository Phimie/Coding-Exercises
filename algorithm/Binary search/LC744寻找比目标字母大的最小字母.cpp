#include <vector>
#include <iostream>

class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int i = 0, j = letters.size();
        while (i < j)
        {
            int mid = i + ((j - i) >> 1); // 2,f  //1,c //0,c
            if (letters[mid] > target)
            {
                j = mid;
            }
            else if (letters[mid] <= target)
            {
                i = mid + 1;
                // while (letters[mid] <= target)
                // {
                //     mid++;
                // }
                // return letters[mid];
            }
        }
        if (i > letters.size() - 1)
        {
            if (letters[i - 1] > target)
            {
                return letters[i];
            }
        }
        else
        {
            if (letters[i] > target)
            {
                return letters[i];
            }
        }

        return letters[0];
    }
};

int main()
{
    Solution s1;
    std::vector<char> letters = {'c', 'c', 'f', 'j'};
    std::cout << s1.nextGreatestLetter(letters, 'c');
    return 0;
}