// 类,成员函数做友元
#include <iostream>
#include <string>

class Building
{
    // GoodGay类是本类的好朋友,可以访问本类的私有成员
    friend class GoodGay;
    friend void GoodGay::visit(); // 告诉Building`类,goodgay类中的visit函数是它的好朋友,可以访问私有成员

public:
    Building();

public:
    std::string m_SittingRoom;

private:
    std::string m_BedRoom;
};

class GoodGay
{
public:
    GoodGay();
    void visit(); //  参观函数  访问Building中的属性
    Building *building;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    // 创建建筑物对象
    building = new Building;
}

void GoodGay::visit()
{
    std::cout << "好朋友类正在访问:" << building->m_BedRoom << std::endl;
}

// 测试案例1
void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();
    return 0;
}
