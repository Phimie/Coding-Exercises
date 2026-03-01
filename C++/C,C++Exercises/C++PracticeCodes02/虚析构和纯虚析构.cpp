/*
虚析构和纯虚析构共性:
1.可以解决父类指针释放子类对象
2.都需要有具体的函数实现

虚析构和纯虚析构区别:
1.如果是纯虚析构,该类属于抽象类,无法实例化对象
2.纯虚析构需要有具体代码实现
*/

#include <iostream>
#include <string>

class Animal
{
public:
    Animal()
    {
        std::cout << "父类构造函数调用" << std::endl;
    }

    // virtual ~Animal()                // 利用虚析构函数 使父类指针在析构的时候,调用子类中的析构函数
    // {
    //     std::cout << "父类析构函数调用" << std::endl;
    // }

    virtual ~Animal() = 0; // 纯虚析构  一定要有具体的代码实现

    virtual void speak() = 0; // 纯虚函数
};

Animal::~Animal() // Animal纯虚析构的具体实现
{
    std::cout << "Animal纯虚析构函数调用" << std::endl;
}

class Cat : public Animal
{
public:
    Cat(std::string name)
    {
        m_Name = new std::string(name);
        std::cout << "子类构造函数调用" << std::endl;
    }

    virtual void speak()
    {
        std::cout << *m_Name << " 小猫在说话" << std::endl;
    }

    ~Cat() // 子类的析构函数,父类指针在析构的时候,不会调用子类中的析构函数
    {
        std::cout << "子类析构函数调用" << std::endl;
        if (m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
        }
    }

public:
    std::string *m_Name; // 子类的堆区属性,
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构的时候  不会调用子类中的析构函数,导致子类如果有堆区属性,出现内存泄漏;
    delete animal;
}

int main()
{
    test01();
    return 0;
}
