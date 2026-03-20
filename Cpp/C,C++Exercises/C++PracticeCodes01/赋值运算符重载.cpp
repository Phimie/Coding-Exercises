// 如果类中又属性指向堆区,做赋值操作时也会出现深浅拷贝问题

#include <iostream>
#include <string>

class Student
{
public:
    Student(int age)
    {
        m_Age = new int(age);
    }
    ~Student()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载 赋值运算符
    Student &operator=(Student &s) // 引用传递
    {
        // 编译器是提供浅拷贝
        // m_Age = p.m_Age;

        // 应该先判断释放有属性在堆区,如果有先释放干净,然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age; // 释放,避免内存泄漏问题
            m_Age = NULL;
        }

        // 深拷贝
        m_Age = new int(*s.m_Age);

        // 返回对象本身
        return *this;
    }

public:
    int *m_Age;

private:
};

void test01()
{
    Student s1(18);
    Student s2(20);
    Student s3(30);
    s3 = s2 = s1; // 简单赋值操作,做的是浅拷贝(包括了堆区同一内存的重复释放),有概率导致程序崩溃;
    // 解决办法:将赋值运算符重载,将浅拷贝变成深拷贝
    std::cout << "s1的年龄为:" << *s1.m_Age << std::endl;
    std::cout << "s2的年龄为:" << *s2.m_Age << std::endl;
    std::cout << "s3的年龄为:" << *s3.m_Age << std::endl;
}

int main()
{
    test01();
    return 0;
}