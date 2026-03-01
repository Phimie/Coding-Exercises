// 递增运算符重载
#include <iostream>
#include <string>

class MyInteger
{
    friend std::ostream &operator<<(std::ostream &cout, const MyInteger &myint);

public:
    MyInteger() : m_Num(0)
    {
    }

public:
    // 重载前置++运算符
    MyInteger &operator++()
    {
        m_Num++;
        return *this; // 将自身进行返回
    }
    // 重载后置++运算符
    MyInteger operator++(int) // int 代表占位参数,可以用于区分前置和后置递增
    {                         // 后置递增返回的是一个值而不是引用
        // 先 返回结果
        MyInteger temp = *this;
        // 后 递增
        m_Num++;
        // 最后将记录结果做返回
        return temp;
    }

private:
    int m_Num;
};

// 利用全局函数重载左移运算符
std::ostream &operator<<(std::ostream &cout, const MyInteger &myint)
/*
引用分为两种引用:
第一种:非常量引用
    特性:
    1.必须绑定到一个非常量(可修改)的对象上
    2.不能绑定到临时对象    ------>这也就是为什么这里要用常量引用:重载后置++运算符函数中返回的是值!返回值的时候会自动创建临时对象
    3.引用的对象可以被修改

第二种:常量引用
    特性:
    1.可以绑定到任何对象上
    2.引用的对象不能被修改

关于临时对象:
    临时对象是在表达式求值过程中自动创建的，并且在表达式结束后被销毁。临时对象通常用于函数返回值、表达式求值等场景。
    临时对象是只读的,不能被修改


*/

{
    std::cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;
    std::cout << ++myint << std::endl;
}

void test02()
{
    MyInteger myint;
    std::cout << myint++ << std::endl;
    std::cout << myint << std::endl;
}

int main()
{
    std::cout << "案例一:" << std::endl;
    test01();
    std::cout << "案例二:" << std::endl;
    test02();
    return 0;
}
