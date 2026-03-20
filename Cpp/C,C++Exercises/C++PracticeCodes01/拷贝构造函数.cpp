// 练习拷贝构造函数
#include <iostream>
// 创建一个实例类
class Student
{
public:
    Student() // 默认构造函数
    {
        std::cout << "默认构造函数的调用" << std::endl;
    }
    Student(int a) // 有参构造函数
    {
        std::cout << "有参构造函数的调用" << std::endl;
    }
    Student(const Student &s) // 拷贝构造函数
    {
        std::cout << "拷贝构造函数的调用" << std::endl;
        S_Age = s.S_Age;
    }
    ~Student() // 析构函数
    {
        std::cout << "析构函数的调用" << std::endl;
    }

    // 实现
    void change_age(int a)
    {
        S_Age = a;
    }
    int get_age()
    {
        return S_Age;
    }

private:
    int S_Age = 0;
};

// 触发默认构造函数:
//  void creat_student(Student &s, int a)
//  {
//      s.change_age(a);
//  }

int main()
{
    Student s1; // 触发默认构造函数
    //    creat_student(s1, 18);
    Student s2(10); // 触发有参构造函数

    Student s3(s1); // 触发拷贝构造函数
    return 0;
}

// 总结:
//  拷贝构造函数通常用在想要拷贝一个对象的时候