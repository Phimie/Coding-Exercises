#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped)
    {
        std::vector<int> arr;
        for (int i = 0, j = 0; i < pushed.size(); i++)
        {
            arr.push_back(pushed[i]);
            while (!arr.empty() && arr.back() == popped[j])
            {
                arr.pop_back();
                j++;
            }
        }
        return arr.empty();
    }
};

int main()
{

    Solution s1;
    std::vector<int> n1 = {1, 2, 3, 4, 5};
    std::vector<int> n2 = {4, 3, 5, 1, 2};
    std::cout << s1.validateStackSequences(n1, n2) << std::endl;

    return 0;
}
