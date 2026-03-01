#include <iostream>
#include "workerManager.h"
#include "workerManager.cpp"
#include "worker.h"
#include "worker.cpp"
#include "employee.h"
#include "employee.cpp"
#include "manager.h"
#include "manager.cpp"
#include "boss.h"
#include "boss.cpp"

int main()
{
    WorkerManager wm;

    int choice = 0;

    while (true)
    {
        wm.Show_Menu();
        std::cout << "请选择一个选项:";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 0: // 退出系统
            wm.exitSystem();
            break;
        case 1: // 添加职工
            wm.Add_Emp();
            break;
        case 2: // 显示职工
            break;
        case 3: // 删除职工
            break;
        case 4: // 修改职工
            break;
        case 5: // 查找职工
            break;
        case 6: // 排序职工
            break;
        case 7: // 清空文件
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}