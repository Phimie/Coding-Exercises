// 继承
// class 子类 : 继承方式  父类
#include <iostream>
#include <string>

class Base
{
public:
    Base() : m_name(100)
    {
        std::cout << "Base的构造函数调用" << std::endl;
    }
    ~Base()
    {
        std::cout << "Base的析构函数调用" << std::endl;
    }
    int m_age;
    int m_name;
    void func()
    {
        std::cout << "Base func调用" << std::endl;
    }

public:
private:
    int m_c;
};

class Base2
{
public:
    int abe;
    void func()
    {
        std::cout << "Base2函数调用" << std::endl;
    }
};

class Son : public Base, public Base2 // C++中允许多父类
{
public:
    Son() : m_name(200)
    {
        std::cout << "Son的构造函数调用" << std::endl;
    }
    ~Son()
    {
        std::cout << "Son 的析构函数调用" << std::endl;
    }
    int m_D;
    int m_name; // 子类中与父类同名的成员
    void func()
    {
        std::cout << "Son func调用" << std::endl;
    }

private:
};

void test01()
{
    Son s1; // 先调用父类的构造函数,后调用子类的构造函数
    std::cout << sizeof(s1) << std::endl;
    // 同名的属性处理方式
    std::cout << "Son 下的 m_name = " << s1.m_name << std::endl;
    std::cout << "Base 下的 m_name = " << s1.Base::m_name << std::endl; // 通过子类对象访问父类同名成员需要加作用域

    // 同名的函数处理方式
    s1.func();       // 直接调用 调用的是子类中的同名成员
    s1.Base::func(); // 通过子类对象访问父类同名函数需要加作用域
    s1.Base2::func();
}

int main()
{
    test01();
    return 0;
}
