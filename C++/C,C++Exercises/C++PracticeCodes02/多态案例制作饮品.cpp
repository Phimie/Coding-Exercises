#include <iostream>
#include <string>

// 制作饮品
class AbstractDrinking
{
public:
    // 煮水
    virtual void Boil() = 0; // 纯虚函数

    // 冲泡
    virtual void Brew() = 0;

    // 倒入杯中
    virtual void PourInCup() = 0;

    // 加入辅料
    virtual void PutSomething() = 0;

    // 制作饮品
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        std::cout << "煮农夫山泉" << std::endl;
    }
    virtual void Brew()
    {
        std::cout << "冲泡咖啡" << std::endl;
    }
    virtual void PourInCup()
    {
        std::cout << "倒入杯中" << std::endl;
    }
    virtual void PutSomething()
    {
        std::cout << "加入糖和牛奶" << std::endl;
    }
};

// 制作茶水
class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        std::cout << "煮矿泉水" << std::endl;
    }
    virtual void Brew()
    {
        std::cout << "冲泡茶叶" << std::endl;
    }
    virtual void PourInCup()
    {
        std::cout << "倒入杯中" << std::endl;
    }
    virtual void PutSomething()
    {
        std::cout << "加入枸杞" << std::endl;
    }
};

// 制作函数
void doWork(AbstractDrinking *abs) // AbstractDrinking * abs = new Coffee
{
    abs->makeDrink();
    delete abs; // 释放
}

void test01()
{
    // 制作咖啡
    doWork(new Coffee);
    std::cout << "------------------------" << std::endl;
    // 制作茶叶
    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}
