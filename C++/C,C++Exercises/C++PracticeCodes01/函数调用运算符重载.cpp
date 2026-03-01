// 函数调用运算符()重载
// 由于重载后使用的方式非常像函数的调用,因此称为仿函数

#include <iostream>
#include <string>

class MyPrint
{
public:
    // 重载函数调用运算符

    void operator()(std::string test)
    {
        std::cout << test << std::endl;
    }

public:
private:
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("Hello world"); // 由于使用起来非常类似于函数调用,因此称为仿函数;
}
void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    std::cout << "ret = " << ret << std::endl;

    std::cout << MyAdd()(100, 100) << std::endl; // 匿名函数对象
}
int main()
{
    test01();
    test02();
    return 0;
}