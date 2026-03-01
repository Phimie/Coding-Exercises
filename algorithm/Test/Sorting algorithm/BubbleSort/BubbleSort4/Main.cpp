#include <iostream>
#include <algorithm>
int main()
{
    const int n = 10;
    int arr[n] = {1, 2, 5, 3, 7, 4, 5, 9, 3, 3};

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}