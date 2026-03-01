#include <iostream>
// 动态数组类
class DynamicArray
{
private:
    int size = 0;
    int capacity = 8;
    int *array = new int[capacity];

private:
    // 移动元素
    void shiftElementsBackward(int arr[], int start, int end)
    {
        // 检查参数
        if (start < 0 || start >= size || end < 0 || end >= size || start > end)
        {
            std::cerr << "传入参数有误!" << std::endl;
            return;
        }

        for (int i = end; i >= start; i--)
        {
            if (i + 1 < capacity)
            {
                arr[i + 1] = arr[i];
            }
            else
            {
                std::cerr << "数组容量不够!" << std::endl;
                return;
            }
        }
    }

    void shiftElementsForward(int arr[], int start, int end)
    {
        // 检查参数
        if (start < 0 || start >= size || end < 0 || end >= size || start > end)
        {
            std::cerr << "传入参数有误!" << std::endl;
            return;
        }
        for (int i = start; i <= end; i++)
        {
            if (i - 1 >= 0)
            {
                arr[i - 1] = arr[i];
            }
            else
            {
                std::cerr << "数组越界!" << std::endl;
                return;
            }
        }
    }
    // 容量检查
    void checkCapacity()
    {
        if (size == capacity)
        {
            capacity += capacity >> 1; // 扩大到原容量的1.5倍
            int *newArray = new int[capacity];
            for (int i = 0; i < size; i++) // 数据copy到新数组
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    ~DynamicArray()
    {
        delete[] array;
    }

public:
    // 添加到最后
    void addLast(int element)
    {
        checkCapacity();
        array[size] = element;
        size++;
    }
    // 插入值
    void add(int index, int element)
    {
        // 容量检查
        checkCapacity();

        if (index >= 0 && index < size)
        {
            shiftElementsBackward(array, index, size - 1);
            array[index] = element;
            size++;
        }
        else if (index == size)
        {
            array[index] = element;
            size++;
        }
    }
    // 遍历
    void forEach()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << ",";
        }
    }
    // 删除
    int remove(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cerr << "传入参数有误" << std::endl;
            return -1;
        }
        int removed = array[index];
        if (index < size - 1)
        {
            shiftElementsForward(array, index + 1, size - 1);
        }
        size--;
        return removed;
    }
    // 获取大小
    int Size()
    {
        return size;
    }
    // 读取指定元素
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cerr << "传入参数有误" << std::endl;
            return -1;
        }
        return array[index];
    }
    // 清空数组
    void clear()
    {
        delete[] array;
        size = 0;
        capacity = 8;
        array = new int[capacity];
    }

    // 获取容量

    int getCapacity()
    {
        return capacity;
    }
};

int main()
{

    DynamicArray array;
    for (int i = 1; i < 6; i++)
    {
        array.addLast(i);
    }
    array.forEach();
    std::cout << std::endl;
    array.add(1, 8);
    array.forEach();
    std::cout << std::endl;
    array.remove(3);
    array.forEach();
    std::cout << std::endl;
    std::cout << "目前size为:" << array.Size() << std::endl;
    std::cout << "目前容量为:" << array.getCapacity();
    std::cout << std::endl;
    for (int i = 1; i < 6; i++)
    {
        array.addLast(i);
    }
    array.forEach();
    std::cout << std::endl;
    std::cout << "目前size为:" << array.Size() << std::endl;
    std::cout << "目前容量为:" << array.getCapacity();
    std::cout << std::endl;
    for (int i = 1; i < 6; i++)
    {
        array.addLast(i);
    }
    array.forEach();
    std::cout << std::endl;
    std::cout << "目前size为:" << array.Size() << std::endl;
    std::cout << "目前容量为:" << array.getCapacity();
    return 0;
}