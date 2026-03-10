#include <vector>
class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int left = 0, right = letters.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (letters[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return letters[left % letters.size()];
    }
};