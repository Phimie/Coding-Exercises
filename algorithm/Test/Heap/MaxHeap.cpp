#include <iostream>
#include <vector>

class MaxHeap
{
    std::vector<int> heap;

private:
    void HeapifyUp(int index) // index = heap.size() - 1
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index])
            {
                std::swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void HeapifyDown(int index) // index = 0
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < heap.size() && heap[largest] < heap[left])
            {
                largest = left;
            }
            if (right < heap.size() && heap[largest] < heap[right])
            {
                largest = right;
            }
            if (largest == index)
            {
                break;
            }
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void push(int value)
    {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    bool pop()
    {
        if (heap.empty())
        {
            return false;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (heap.empty())
        {
            return false;
        }
        HeapifyDown(0);
        return true;
    }
};
int main()
{
    return 0;
}
