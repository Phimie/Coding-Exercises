#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 1000

struct Person
{
    std::string name;
    long long phoneNumber;
    std::string address;
    int sex;
};

struct Contact
{
    struct Person personArr[MAX];
    int personCount;
};

int ShowMenu()
{
    std::cout << "**************************" << std::endl;
    std::cout << "*****  1.添加联系人  *****" << std::endl;
    std::cout << "*****  2.删除联系人  *****" << std::endl;
    std::cout << "*****  3.显示联系人  *****" << std::endl;
    std::cout << "*****  4.退出通讯录  *****" << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << "请选择: ";
    int option = 0;
    std::cin >> option;
    return option;
}
void AddContact(Contact *abs)
{
    if (abs->personCount == MAX)
    {
        std::cout << "通讯录已满, 无法添加!" << std::endl;
        return;
    }
    else
    {
        std::cout << "请输入联系人的姓名: ";
        std::cin >> abs->personArr[abs->personCount].name;
        std::cout << "请输入联系人的电话号码: ";
        while (std::cin >> abs->personArr[abs->personCount].phoneNumber)
        {
            if (abs->personArr[abs->personCount].phoneNumber < 0)
            {
                std::cout << "输入错误, 请重新输入!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
            else
            {
                break;
            }
        }
        std::cout << "请输入联系人的性别(1.男 2.女): ";
        int sex;
        std::cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->personArr[abs->personCount].sex = sex;
        }
        else
        {
            std::cout << "输入错误, 请重新输入!" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        std::cout << "请输入联系人的地址: ";
        std::cin >> abs->personArr[abs->personCount].address;
        abs->personCount++;
        std::cout << "添加成功!" << std::endl;
        system("pause");
        system("cls");
    }
}
int DeleteContact(Contact *abs, std::string name)
{
    for (int i = 0; i < abs->personCount; i++)
    {
        if (abs->personArr[i].name == name)
        {
            return i;
            break;
        }
    }
    return -1;
}

void DeletePerson(Contact *abs)
{
    std::cout << "请输入要删除的联系人姓名: ";
    std::string name;
    std::cin >> name;
    int index = DeleteContact(abs, name);
    if (index == -1)
    {
        std::cout << "查无此人!" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = index; i < abs->personCount; i++)
        {
            abs->personArr[i] = abs->personArr[i + 1];
        }
        abs->personCount--;
        std::cout << "删除成功!" << std::endl;
        system("pause");
        system("cls");
    }
}
void ShowContact(Contact abs)
{
    if (abs.personCount == 0)
    {
        std::cout << "通讯录为空!" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = 0; i < abs.personCount; i++)
        {
            std::cout << "姓名: " << abs.personArr[i].name << " 电话号码: " << abs.personArr[i].phoneNumber << " 性别: " << (abs.personArr[i].sex == 1 ? "男" : "女") << " 地址: " << abs.personArr[i].address << std::endl;
        };
        system("pause");
        system("cls");
    }
}

void Exit()
{
    std::cout << "感谢使用通讯录管理系统!" << std::endl;
    system("pause");
    exit(0);
}

int main()
{
    Contact abs;
    abs.personCount = 0;

    while (true)
    {
        switch (ShowMenu())
        {
        case 1:
        {
            AddContact(&abs);
            break;
        }
        case 2:
        {
            DeletePerson(&abs);
            break;
        }
        case 3:
        {
            ShowContact(abs);
            break;
        }
        case 4:
        {
            Exit();
            break;
        }
        default:
        {
            std::cout << "输入错误, 请重新输入!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            system("cls");
            break;
        }
        }
    }
    return 0;
}
