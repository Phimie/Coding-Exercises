#include <iostream>
#include <algorithm>

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            arr[i++] = arr[j];
        }
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }
        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }
    arr[i] = pivot;

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main()
{
    int arr[] = {6, 2, 8, 1, 5, 3};
    quickSort(arr, 0, 5);
    for (int i : arr)
    {
        std::cout << i << " ";
    }
}