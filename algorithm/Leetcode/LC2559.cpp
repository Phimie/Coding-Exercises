#include <iostream>
#include <vector>
#include <string>
class Solution
{
public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> prefix((int)words.size() + 1, 0);
        int count = 0;
        for (int i = 0; i < (int)words.size(); i++)
        {
            count = 0;
            if ((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][words[i].size() - 1] == 'a' || words[i][words[i].size() - 1] == 'e' || words[i][words[i].size() - 1] == 'i' || words[i][words[i].size() - 1] == 'o' || words[i][words[i].size() - 1] == 'u'))
                count++;
            prefix[i + 1] = prefix[i] + count;
        }
        std::vector<int> ans((int)queries.size(), 0);
        for (int i = 0; i < (int)queries.size(); i++)
        {
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }
        return ans;
    }
};

int main()
{
    std::vector<std::string> words = {"aba", "bcb", "ece", "aa", "e"};
    std::vector<std::vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    Solution s1;
    for (int n : s1.vowelStrings(words, queries))
    {
        std::cout << n << ",";
    }
    return 0;
}