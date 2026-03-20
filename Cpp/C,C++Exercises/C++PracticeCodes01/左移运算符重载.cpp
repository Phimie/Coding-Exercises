// 左移运算符重载

#include <iostream>
#include <string>

class Student
{
    friend std::ostream &operator<<(std::ostream &cout, Student &s);

public:
    // 成员函数没办法重载左移运算符,因为无法实现cout在左侧;

    Student(); // 默认构造函数声明
    int get_m_age()
    {
        return m_age;
    }

public:
    std::string m_name;

private:
    int m_age;
    int m_ID;
};

// 只能利用全局函数重载左移运算符
std::ostream &operator<<(std::ostream &cout, Student &s) // 本质是operator<<(cout,p),所以可以简化为cout << p
{
    std::cout << "m_age=" << s.m_age << ",m_ID=" << s.m_ID;
    return cout; // 继续返回cout,满足链式编程思想
}

Student::Student() : m_age(10), m_ID(20) // 初始化列表+类外声明
{
}

// 案例一:
void test01()
{
    Student s1;
    std::cout << s1 << std::endl; // 链式编程思想
}

int main()
{
    test01();
    return 0;
}