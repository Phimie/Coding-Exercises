#include <iostream>
int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 4};
    int Bucket[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        Bucket[arr[i]]++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < Bucket[i]; j++)
        {
            std::cout << i << ",";
        }
    }
    return 0;
}