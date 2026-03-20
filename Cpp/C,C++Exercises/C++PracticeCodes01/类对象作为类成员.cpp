// 对象成员:类对象作为类成员

#include <iostream>
#include <string>
class Phone
{
public:
    Phone(std::string Brand) : p_Brand(Brand) // 构造函数
    {
        std::cout << "Phone的构造函数调用" << std::endl;
    }

    ~Phone()
    {
        std::cout << "Phone的析构函数的调用" << std::endl;
    }

    std::string p_Brand;
};

class Student
{
public:
    Student(std::string name, std::string p_brand) : s_Name(name), s_Phone(p_brand) // 构造函数
    {
        std::cout << "Student的构造函数调用" << std::endl;
    }

    ~Student()
    {
        std::cout << "Student的析构函数的调用" << std::endl;
    }

    std::string s_Name;
    Phone s_Phone;
};

void test01()
{
    Student s1("张三", "IQOO 12");
    std::cout << s1.s_Name << "拿着" << s1.s_Phone.p_Brand << std::endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}

// 总结:
// 当其他类对象作为本类的成员的时候,构造的时候先构造其它类对象,再构造自身
// 先关闭本类,再关闭其他类对象,即析构的顺序与构造相反