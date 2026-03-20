// const修饰成员函数
// 常函数:成员函数后加const,常函数内不可以修改成员属性,除非在成员属性声明时加关键字mutable

// 常对象:声明对象前加const称该对象为常对象,常对象只能调用常函数

#include <iostream>

class Student
{
public:
    Student() // 默认构造函数
    {
    }
    void showStudent() const // 常函数
    {
        /*
        this -> m_Age = 100;

        这段语句是错误的,因为这里this是常函数中的this
        相当于const Student * const this
        */
        this->m_B = 100;
        // 这段语句是正确的,因为m_B加了关键字mutable
    }
    void func() {}
    int m_Age;
    mutable int m_B; // 特殊变量,即使在常函数中,也可以修改这个值,加关键字mutable
};

void test01()
{
    Student s1;
    s1.showStudent();
}

void test02()
{
    const Student s2; // 在对象前加const,变为常对象
                      /*
                      s2.m_A = 100;
                  
                      这段语句是错误的,常对象无法修改
                      */
    s2.m_B = 100;
    // 这是正确的,因为m_B的特殊性
}

int main()
{
    test01();
    return 0;
}

// this指针的本质是指针常量,指针的指向是不可以改变的,但是指针的值是可以改变的
// this指针就是:Student * const this;

/*
在常函数中的this指针相当于:
const Student * const this;

所以在常函数中,不可以修改成员属性
*/
