// SelectionSort

#include <iostream>
void SelectionSort(int arr[], int n)
{
    int minIndex = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ",";
    }
}
int main()
{
    int arr[10] = {2, 4, 6, 8, 8, 1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "排序前为:";
    printArr(arr, n);
    std::cout << std::endl;

    SelectionSort(arr, n);
    std::cout << "排序后为:";
    printArr(arr, n);

    return 0;
}