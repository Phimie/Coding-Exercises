// 成员变量和成员函数是分开存储的

#include <iostream>
class Student
{
public:
    int S_age;
    static int S_B; // 静态成员变量不属于类对象上,所以sizeof时没有增加内存占用

    void func() // 非静态成员函数  也不属于类对象上
    {
    }

    static void func2() // 静态成员变量   也不属于类对象上
    {
    }
};
int Student::S_B = 0;
void test01()
{
    Student s1;
    // C++编译器会给每个空对象也分配一个字节空间,是未来区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    std::cout << "Size of p = " << sizeof(s1) << std::endl;
}
void test02()
{
}
int main()
{
    std::cout << "测试案例1:" << std::endl;
    test01();
    std::cout << "测试案例2:" << std::endl;
    test02();
    return 0;
}

// 注意:空对象占用内存为1