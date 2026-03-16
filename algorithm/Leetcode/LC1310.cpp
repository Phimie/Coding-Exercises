#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries)
    {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        std::vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++)
        {
            ans[i] = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<int> arr = {4, 8, 2, 10};
    std::vector<std::vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
    for (int n : s1.xorQueries(arr, queries))
    {
        std::cout << n << ',';
    }
    return 0;
}