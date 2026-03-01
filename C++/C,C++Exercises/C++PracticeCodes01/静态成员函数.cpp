#include <iostream>
#include <string>

class Student
{
public:
    static void func() // 静态成员函数
    {
        S_age = 100;
        std::cout << "static void func的调用" << std::endl;
    }

    static int S_age; // 静态成员变量
};

int Student::S_age = 0;

void test01()
{
    std::cout << "通过对象访问func" << std::endl;
    Student s1;
    s1.func();

    std::cout << "通过类名进行访问func" << std::endl;
    Student::func();
}

int main()
{
    test01();
    return 0;
}

// 重点总结:
// 静态成员函数只能访问静态成员变量