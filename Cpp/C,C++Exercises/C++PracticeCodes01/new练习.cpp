#include <iostream>
int *creat_pointer()
{
    int *p = new int(10);
    return p;
}
void delete_pointer(int *p)
{
    delete p;
}

int *creat_arr_pointer()
{
    int *arr = new int[10];
    return arr;
}
void delete_arr_pointer(int *arr)
{
    delete[] arr;
}
int main()
{
    int *p = creat_pointer();
    std::cout << *p << std::endl;
    std::cout << p << std::endl;
    delete_pointer(p);
    int *arr = creat_arr_pointer();
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 100 + i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
    delete_arr_pointer(arr);
}