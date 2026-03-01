#include <iostream>
#include <string>
#include <ctime>
int main()
{
    srand(time(0));
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}