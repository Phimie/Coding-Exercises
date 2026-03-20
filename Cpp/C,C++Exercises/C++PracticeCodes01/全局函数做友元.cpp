///////////////////全局函数做友元
#include <iostream>
#include <string>

class Building
{
    // 全局函数做友元,使goodgay能够访问private
    friend void goodGay(Building *B);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    std::string m_SittingRoom;

private:
    std::string m_BedRoom;
};

// 全局函数
void goodGay(Building *B)
{
    std::cout << "好朋友的全局函数正在访问:" << B->m_SittingRoom << std::endl;

    std::cout << "好朋友的全局函数正在访问:" << B->m_BedRoom << std::endl;
}

void test01()
{
    Building B1;
    goodGay(&B1);
}

int main()
{
    test01();
    return 0;
}
