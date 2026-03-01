// SelectionSort2
#include <iostream>
int main()
{
    int arr[10] = {1, 3, 5, 2, 9, 7, 4, 6, 3, 2};
    int minIndex = 0, temp = 0;
    for (int i = 0; i < 10; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    std::cout << "排序后为:";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ",";
    }
    return 0;
}