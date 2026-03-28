#include <iostream>
#include <vector>

class MinHeap
{

private:
    std::vector<int> heap;
    // 上浮
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent])
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    // 下沉
    void heapifyDown(int index)
    {
        int size = heap.size();
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
            {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest])
            {
                smallest = right;
            }
            if (smallest == index)
            {
                break;
            }

            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    // 插入元素
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // 删除堆顶
    void pop()
    {
        if (heap.empty())
        {
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
    }

    // 获取堆顶
    int top() const
    {
        if (heap.empty())
        {
        }
        return heap[0];
    }
    // 返回堆的大小
    size_t size() const
    {
        return heap.size();
    }
    // 判断堆是否为空
    bool empty() const
    {
        return heap.empty();
    }
};

int main()
{
    return 0;
}