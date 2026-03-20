#include <iostream>

class Student
{
public:
    Student()
    {
        std::cout << "默认构造函数调用" << std::endl;
    }
    Student(int s_age, int s_height)
    {
        height = new int(s_height);
        age = s_age;
        std::cout << "有参构造函数调用" << std::endl;
    }
    Student(const Student &s) // 自定义拷贝构造函数来实现深拷贝
    {
        std::cout << "拷贝构造函数调用" << std::endl;
        age = s.age;
        height = new int(*s.height);
    }
    ~Student()
    {
        if (height != NULL)
        {
            delete height; // 调用析构函数的时候把调用的内存清空
            height = NULL;
        }
        std::cout << "析构函数调用" << std::endl;
    }

    int age = 0;
    int *height = 0;
};

void test01()
{
    Student s1(18, 160);
    std::cout << "s1的年龄为:" << s1.age << ",身高为:" << *s1.height << std::endl;
    Student s2(s1); // 如果未自定义拷贝函数,系统会自动执行浅拷贝,浅拷贝会将所有信息原封不动复制过去(包括指针指向的地址),
    // 这个时候执行析构函数的时候会重复释放同一个地址,导致双重释放问题!
    std::cout << "s2的年龄为:" << s2.age << ",身高为:" << *s2.height << std::endl;
}

int main()
{
    test01();
    return 0;
}

// 2025.5.27