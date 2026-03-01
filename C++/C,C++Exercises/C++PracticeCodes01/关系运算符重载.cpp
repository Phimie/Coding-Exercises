// 关系运算符重载

#include <iostream>
#include <string>
class Student
{
public:
    Student(std::string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载关系运算符
    bool operator==(Student s)
    {
        if (this->m_Name == s.m_Name && this->m_Age == s.m_Age)
        {
            return true;
        }
        return false;
    }

public:
    std::string m_Name;
    int m_Age;

private:
};
void test01()
{
    Student s1("张三", 18);
    Student s2("李四", 80);
    Student s3("张三", 18);
    if (s1 == s2)
    {
        std::cout << "两个对象是相等的" << std::endl;
    }
    else
    {
        std::cout << "两个对象不相等" << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}
