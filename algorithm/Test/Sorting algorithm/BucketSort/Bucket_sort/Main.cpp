#include <iostream>

int main()
{
    int n;
    std::cout << "需要排序多少个数字:";
    std::cin >> n;
    std::cout << std::endl;
    int *arr = new int[n];
    std::cout << "请输入" << n << "个数字(用空格分隔):";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    int **buckets = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        buckets[i] = new int[n];
    }
    int bucketSize[10] = {0};
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        buckets[num][bucketSize[num]] = num;
        bucketSize[num]++;
    }

    int index = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bucketSize[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    for (int i = 0; i < 10; i++)
    {
        delete[] buckets[i];
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}