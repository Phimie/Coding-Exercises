// BucketSort4
#include <iostream>
int main()
{
    const int n = 10;
    int Bucket[10] = {0};
    int arr[n] = {2, 3, 6, 1, 3, 9, 7, 5, 4, 3};
    for (int i : arr)
    {
        Bucket[i]++;
    }

    for (int i = 0; i < 10; i++)
    {
        int count = Bucket[i];
        while (count-- > 0) // 通过用while递减循环减少条件判断次数
        {
            std::cout << i << " ";
        }
    }
    return 0;
}