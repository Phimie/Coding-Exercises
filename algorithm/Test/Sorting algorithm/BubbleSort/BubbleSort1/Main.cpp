// https://910.tsss123.cc/api/v1/client/subscribe?token=b0de62a15ce9cbfd69d81b2375b6d946
#include <iostream>

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 5, 7, 9, 1, 3, 6, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " "; //
    }
    system("pause");
    return 0;
}