#include <iostream>
#include <string>
class Student
{
public:
    void change_name(std::string a)
    {
        name = a;
    }
    std::string get_name()
    {
        return name;
    }
    void change_age(int a)
    {
        if (a > 0 && a < 150)
        {
            age = a;
        }
        else
        {
            std::cout << "年龄" << a << "输入错误!更改失败!" << std::endl;
            return;
        }
    }
    int get_age()
    {
        return age;
    }
    void change_ID(std::string a)
    {
        ID = a;
    }
    std::string get_ID()
    {
        return ID;
    }

private:                    // 把成员变量封装在private下,这样做可以自由控制这些属性的读写权限
    std::string name = " "; // 可读可写
    int age = 0;            // 可读可写
    std::string ID = " ";   // 可读可写
};

int main()
{
    Student zhangsan;
    std::string name = "";
    int age = 0;
    std::string ID = "";

    std::cout << "请输入你的名字:" << std::endl;
    std::cin >> name;

    std::cout << "请输入你的年龄:" << std::endl;
    std::cin >> age;

    std::cout << "请输入你的学号:" << std::endl;
    std::cin >> ID;

    zhangsan.change_name(name);
    std::cout << "学生的名字是:" << zhangsan.get_name() << std::endl;

    zhangsan.change_age(age);
    std::cout << "学生的年龄是:" << zhangsan.get_age() << std::endl;

    zhangsan.change_ID(ID);
    std::cout << "学生的学号是:" << zhangsan.get_ID() << std::endl;
    return 0;
}