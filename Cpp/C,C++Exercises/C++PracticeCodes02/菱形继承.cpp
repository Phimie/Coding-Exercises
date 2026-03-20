// 利用虚继承  解决菱形继承的问题
#include <iostream>
#include <string>

class animal
{
public:
    int m_age = 100;
};

class horse : virtual public animal // 虚继承,animal类称为 虚基类;
{
public:
};

class donkey : virtual public animal // 利用虚继承技术,解决资源浪费问题
{
public:
};

class mule : public horse, public donkey
{
public:
};

void test01()
{
    mule m1;
    m1.m_age = 18;
    m1.donkey::m_age = 20;
    m1.horse::m_age = 30;
    // 当菱形继承,两个父类拥有相同数据,需要加以作用域区分
    std::cout << "horse的age:" << m1.horse::m_age << std::endl;
    std::cout << "donkey的age:" << m1.donkey::m_age << std::endl;
    std::cout << "mule的age:" << m1.m_age << std::endl;

    // 菱形继承导致数据有两份,造成资源浪费
}

int main()
{
    test01();
    return 0;
}
