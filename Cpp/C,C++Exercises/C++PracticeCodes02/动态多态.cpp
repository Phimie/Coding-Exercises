/*
动态多态满足条件 :
1.有继承关系
2.子类要重写父类的虚函数

动态多态的使用:
父类的指针或者引用 执行子类对象

*/
#include <iostream>
#include <string>

class Animal
{
public:
    virtual void speak() // 虚函数
    {
        std::cout << "动物在说话" << std::endl;
    }

private:
};

class Cat : public Animal
{
public:
    void speak() // 子类重写父类的虚函数
    {            // 重写: 函数返回值类型,函数名,参数列表都完全相同
        std::cout << "小猫在说话" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void speak() // 子类重写父类的虚函数
    {
        std::cout << "小狗在说话" << std::endl;
    }
};

// 执行说话的函数
// 地址早绑定    在编译阶段就已经确定了函数地址了

/// 如果想执行让猫说话,那么这个函数地址就不能提前绑定,需要在运行阶段进行绑定,地址晚绑定
/// 简单来说就是用虚函数来解决这个问题
void doSpeak(Animal &animal) // Animal & animal = cat;
{                            // 父类的指针或引用执行子类对象
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    std::cout << "sizeof  Animal = " << sizeof(Animal) << std::endl;
}

int main()
{
    std::cout << "测试一:" << std::endl;
    test01();
    std::cout << std::endl;

    std::cout << "测试二:" << std::endl;
    test02();
    std::cout << std::endl;

    return 0;
}
