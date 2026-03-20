// 谁调用对象的成员函数,this指针就指向谁
// 也就是this指针指向被调用的成员所属的对象

#include <iostream>

class Student
{
public:
    Student(int age)
    {
        // 这里的this指向的是s1,因为是s1在调用它;
        this->age = age;
    }

    Student &StudentAddAge(Student &s) // 记得  如果要返回或读取它的本体,应该用&引用的方式

    /*



    如果这里不是用引用&方式返回的,而是值的方式,
    那么返回的结果将是调用了浅拷贝构造函数复制出来的s2',
    导致后面的链式调用的时候只有第一次返回*this的时候,
    真正的s2加了一次数据,后面的调用都是s2的复制品们在加数据

    所以结果体现为只加了一次数据的s2的年龄



    */

    {
        this->age += s.age;
        return *this; // 这里的this指向的就是s2本身,所以解引用之后返回的就是s2;
    }

    int age; // 这段代码告诉我们:this指针第一个功能是解决名称冲突问题
};

void test01()
{
    Student s1(10);
    std::cout << "s1的年龄为:" << s1.age << std::endl;
}

void test02()
{

    Student s1(20);
    Student s2(10);

    // 链式编程思想:
    s2.StudentAddAge(s1).StudentAddAge(s1).StudentAddAge(s1).StudentAddAge(s1).StudentAddAge(s1); // 得益于函数返回的是对象本身,所以可以多次引用函数进行叠加

    std::cout << "s2的年龄为:" << s2.age << std::endl;
}

int main()
{
    std::cout << "案例一:" << std::endl;
    test01();
    std::cout << "案例二:" << std::endl;
    test02();

    system("pause");
    return 0;
}