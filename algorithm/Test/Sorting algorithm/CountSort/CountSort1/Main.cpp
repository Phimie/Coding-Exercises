// CountSort
#include <iostream>

int serchMax(int arr[])
{
    int n = 0;
    int x = 0;
    n = arr[0];
    for (int i = 0; i < 10; i++)
    {
        x = arr[i];
        if (n < x)
        {
            n = x;
        }
    }
    return n;
}
int serchMin(int arr[])
{
    int n = 0;
    int x = 0;
    n = arr[0];
    for (int i = 0; i < 10; i++)
    {
        x = arr[i];
        if (n > x)
        {
            n = x;
        }
    }
    return n;
}

int main()
{
    int arr[10] = {91, 91, 92, 94, 95, 92, 94, 92, 99, 98};
    int countArr[10] = {0};
    std::cout << "这是数组中最大的数:" << serchMax(arr) << std::endl;
    std::cout << "这是数组中最小的数:" << serchMin(arr) << std::endl;
    int offset = serchMin(arr) - 1; // 通过设置偏移量来节省countarr的空间
    for (int i = 0; i < 10; i++)
    {
        countArr[arr[i] - offset]++;
    }

    std::cout << "最终排序结果是:";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < countArr[i]; j++)
        {
            std::cout << i + offset << ",";
        }
    }
    return 0;
}