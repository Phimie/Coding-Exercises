#include <iostream>
#include <string>
class Solution
{
public:
    void printString(std::string string, int i)
    {
        if (i < 0)
        {
            return;
        }
        std::cout << string[i];
        i--;
        printString(string, i);
    }
};

int main()
{
    Solution s1;
    std::string hello = "hello";
    int i = hello.length();
    s1.printString(hello, i);
}