// 加号运算符重载
// 实现两个自定义数据类型相加的运算
#include <iostream>
#include <string>

class Student
{
    friend Student operator+(Student &s1, Student &s2); // 加号运算符重载作为友元访问private成员

public:
    Student(); // 默认构造函数
    int get_m_age()
    {
        return m_age;
    }

    // 利用成员函数实现加号运算符重载:好处是可以直接访问private成员
    Student operator+(int num) // 运算符重载也可以发生函数重载
    {
        Student temp;
        temp.m_age = this->m_age + num;
        return temp;
    }

public:
    int m_name;

private:
    int m_age;
};

// 类外声明默认构造函数
Student::Student() : m_age(10) // 初始化列表
{
}

// 测试案例1
void test01()
{
    Student s1;
    Student s2;
    Student s3 = s1 + s2; // 运算符重载之后就可以直接用s1 + s2了
    s3 = s3 + 10;

    std::cout << "s3的年龄为:" << s3.get_m_age() << std::endl;
}

Student operator+(Student &s1, Student &s2) // 利用全局函数实现加号运算符重载,
/*
如果这里把引用传递改成值传递的话,
传进去的就是调用s1和s2的默认拷贝构造函数做的浅拷贝副本,
结果不会变但是性能会降低,因为引用传递法不需要创建额外的副本
*/
{
    Student temp;
    temp.m_age = s1.m_age + s2.m_age;
    return temp;
}

int main()
{
    test01();
    return 0;
}

// 2025.5.29
