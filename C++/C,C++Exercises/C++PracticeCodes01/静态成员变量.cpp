#include <iostream>
#include <string>

class Student
{
public:
    static int s_age; // 类内声明
};

int Student::s_age = 100; // 静态成员变量要做类内声明,类外初始化的操作

void test01()
{
    Student s1;
    std::cout << s1.s_age << std::endl;
}

void test02()
{
    std::cout << "1.通过对象进行访问" << std::endl;
    Student s2;
    std::cout << s2.s_age << std::endl;
    std::cout << "2.通过类名进行访问" << std::endl;
    std::cout << Student::s_age << std::endl;
}

void test03()
{
    Student s3;
    s3.s_age = 200;
    std::cout << "s3的数据:" << s3.s_age << std::endl;
    Student s4;
    s4.s_age = 400;
    std::cout << "此时已经将s4的s_age数据更改为400,此时s3.sage为:" << s3.s_age << std::endl;
    // 所有对象共享一个静态成员变量
}

int main()
{
    std::cout << "测试类内声明,类外初始化的操作:" << std::endl;
    test01();
    std::cout << "测试静态成员变量的两种访问方式:" << std::endl;
    test02();
    std::cout << "测试静态成员变量的数据对所有对象是共享的:" << std::endl;
    test03();
    return 0;
}

// 静态成员变量的数据是所有对象共享的
// 且在编译阶段就分配内存