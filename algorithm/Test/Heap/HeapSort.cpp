#include <iostream>
#include <vector>

void heapfyDown(int index, int n, std::vector<int> &arr)
{
    while (true)
    {
        int largest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest == index)
        {
            break;
        }
        std::swap(arr[index], arr[largest]);
        index = largest;
    }
}
void buildHeap(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapfyDown(i, n, arr);
    }
}

int main()
{
    std::vector<int> arr = {2, 4, 6, 1, 3, 5, 7, 8};
    int n = arr.size();

    return 0;
}