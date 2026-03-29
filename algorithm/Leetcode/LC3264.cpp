#include <iostream>
#include <vector>

class MinHeap
{
private:
    std::vector<int> arr;
    void heapifyUp(int index) // index = arr.size() - 1;
    {
        while (index > 0)
        {
            if (arr[(index - 1) / 2] < arr[index])
            {
                std::swap(arr[(index - 1) / 2], arr[index]);
                index = (index - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
    void heapifyDown(int index) // index = 0;
    {
        while (true)
        {
            int smallest = index;
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            if (left < arr.size() && arr[left] < arr[smallest])
            {
                smallest = left;
            }
            if (right < arr.size() && arr[right] < arr[smallest])
            {
                smallest = right;
            }

            if (smallest == index)
            {
                break;
            }
            std::swap(arr[smallest], arr[index]);
            index = smallest;
        }
    }

public:
    MinHeap(std::vector<int> &num)
    {
        arr = num;
    }
    void push(int val)
    {
        arr.push_back(val);
        heapifyUp(arr.size() - 1);
    }

    void pop()
    {
        if (arr.empty())
        {
            return;
        }
        std::swap(arr[0], arr.back());
        arr.pop_back();
        if (arr.empty())
        {
            return;
        }
        heapifyDown(0);
    }
};

class Solution
{
public:
    std::vector<int> getFinalState(std::vector<int> &nums, int k, int multiplier)
    {
        MinHeap heap(nums);
    };
};

int main()
{
    Solution s1;
    std::vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int m = 2;
    return 0;
}