// 初始化列表操作练习
#include <iostream>
class Student
{
public:
    Student(int age_, std::string name_, std::string ID_) : age(age_), name(name_), ID(ID_) // 初始化列表属性
    {
        std::cout << "有参构造函数调用,并执行初始化列表操作" << std::endl;
    }

    int age;
    std::string name, ID;
};

void test01()
{
    Student s1(10, "张三", "02");
    std::cout << "年龄:" << s1.age << std::endl;
    std::cout << "姓名:" << s1.name << std::endl;
    std::cout << "学号:" << s1.ID << std::endl;
}

int main()
{
    test01();
    return 0;
}

// 2025.5.27