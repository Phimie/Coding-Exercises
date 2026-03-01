#include <iostream>
#include <string>

class Student
{
public:
    Student() // 类的构造函数
    {
        std::cout << "正在初始化学生对象..." << std::endl;
    }

    // 一些实现
    void change_name(std::string a)
    {
        name = a;
    }
    std::string get_name()
    {
        return name;
    }
    void change_ID(std::string a)
    {
        ID = a;
    }
    std::string get_ID()
    {
        return ID;
    }
    void change_age(int a)
    {
        age = a;
    }
    int get_age()
    {
        return age;
    }

    ~Student() // 类的析构函数
    {
        std ::cout << std::endl;
        std::cout << "学生对象初始化完毕!" << std::endl;
        std::cout << "姓名:" << name << std::endl;
        std ::cout << "年龄:" << age << std ::endl;
        std ::cout << "学号:" << ID << std::endl;
    }

private:
    std::string name = ""; // 可读可写
    std::string ID = "";   // 可读可写
    int age = 0;           // 可读可写
};

// 创建对象
void create_student(Student &student, std::string name_, std::string ID_, int age_)
{
    student.change_name(name_);
    student.change_ID(ID_);
    student.change_age(age_);
}

int main()
{
    Student student_01; // 创建第一个对象
    int age_ = 0;
    std::string name_, ID_;

    std::cout << "请输入你的名字:";
    std ::cin >> name_;
    std::cout
        << "请输入你的年龄:";
    std::cin >> age_;
    std ::cout
        << "请输入你的学号";
    std::cin >> ID_;
    std::cout << std::endl;
    create_student(student_01, name_, ID_, age_);
    return 0;
}