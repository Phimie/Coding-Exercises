#include <iostream>
#include <string>

class Solution
{
public:
    int maxConsecutiveAnswers(std::string answerKey, int k)
    {
        return std::max(solve(answerKey, k, 'T'),
                        solve(answerKey, k, 'F'));
    }

private:
    int solve(const std::string &s, int k, char target)
    {
        int left = 0, count = 0, maxLen = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] != target)
                count++;
            while (count > k)
            {
                if (s[left] != target)
                    count--;
                left++;
            }
            maxLen = std::max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution s1;
    std::string answerKey = "TTFTTFTT";
    int k = 1;
    std::cout << s1.maxConsecutiveAnswers(answerKey, k) << std::endl;
    return 0;
}