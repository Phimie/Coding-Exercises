#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int calPoints(std::vector<std::string> &operations)
    {
        std::vector<int> ansVector = {};
        for (int i = 0; i < (int)operations.size(); ++i)
        {
            if (operations[i] == "C")
                ansVector.pop_back();
            else if (operations[i] == "D")
                ansVector.push_back(ansVector.back() + ansVector.back());
            else if (operations[i] == "+")
                ansVector.push_back(ansVector[ansVector.size() - 2] + ansVector.back());
            else
                ansVector.push_back(std::stoi(operations[i]));
        }
        int ans = 0;
        for (int i = 0; i < ansVector.size(); ++i)
        {
            ans += ansVector[i];
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    std::vector<std::string> operations = {"5", "2", "C", "D", "+"};
    std::cout << s1.calPoints(operations) << std::endl;
    return 0;
}
