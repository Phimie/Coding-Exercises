#include <iostream>
void func()
{
    std::cout << "函数1" << std::endl;
}
void func(int a)
{
    std::cout << a << std::endl;
}
// 函数重载就是,函数名可以相同,但是作用不同;
int main()
{
    int a = 10;
    func();
    func(a);
    return 0;
}