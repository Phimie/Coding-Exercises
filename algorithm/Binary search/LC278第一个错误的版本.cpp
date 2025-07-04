#include <iostream>
#include <vector>
#include <string>

const int BadVersion = 4;

bool isBadVersion(int version)
{
    return version == BadVersion;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int i = 1, j = n;
        while (i <= j)
        {
            int mid = i + ((j - i) >> 2); // 此处注意>>运算符运算优先级小于+,所以不能写成 int mid = i + (j - i) >> 2;
            if (isBadVersion(mid) == true)
            {

                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};

int main()
{
    Solution s1;
    std::cout << s1.firstBadVersion(5);
    return 0;
}