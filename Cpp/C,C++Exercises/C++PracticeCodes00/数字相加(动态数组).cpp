#include <iostream>

int main()
{
    int n;
    std::cout << "用几个数相加: ";
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "输入第" << i + 1 << "个数" << ": ";
        std::cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    std::cout << "总和为: " << sum << std::endl;
    delete[] arr;
    return 0;
}