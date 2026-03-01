#include <iostream>

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 7};
    int Bucket[11] = {0};

    for (int num : arr)
    {
        Bucket[num]++;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < Bucket[i]; j++)
        {
            std::cout << i << " ";
        }
    }
    system("pause");
    return 0;
}
