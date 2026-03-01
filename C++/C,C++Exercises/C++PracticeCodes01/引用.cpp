#include <iostream>
int main()
{
    int a = 10;
    int &b = a; // 引用一旦初始化了就不可以更改了
    std::cout << b << std::endl;

    // 引用的本质是int *const XX = &XX
    int *const c = &b;

    return 0;
}