#include "workerManager.h"

WorkerManager::WorkerManager()
{
    // 初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

void WorkerManager::Show_Menu()
{
    std::cout << "====================================================" << std::endl;
    std::cout << "----------------欢迎使用职工管理系统----------------" << std::endl;
    std::cout << "----------------   0.退出管理程序   ----------------" << std::endl;
    std::cout << "----------------   1.增加职工信息   ----------------" << std::endl;
    std::cout << "----------------   2.显示职工信息   ----------------" << std::endl;
    std::cout << "----------------   3.删除离职职工   ----------------" << std::endl;
    std::cout << "----------------   4.修改职工信息   ----------------" << std::endl;
    std::cout << "----------------   5.查找职工信息   ----------------" << std::endl;
    std::cout << "----------------   6.按照编号排序   ----------------" << std::endl;
    std::cout << "----------------   7.清空所有文档   ----------------" << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << std::endl;
}

void WorkerManager::exitSystem()
{
    std::cout << "欢迎下次使用!" << std::endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp()
{
    std::cout << "请输入添加职工数量" << std::endl;
    int addNum = 0;
    std::cin >> addNum;

    if (addNum > 0)
    {
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间人数 = 原来记录人数 + 新增人数

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 将原来空间下数据,拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            std::string name;
            int dSelect;

            std::cout << "请输入第" << i + 1 << "个新职工编号:";
            std::cin >> id;
            std::cout << std::endl;

            std::cout << "请输入第" << i + 1 << "个新职工姓名:";
            std::cin >> name;
            std::cout << std::endl;

            std::cout << "请选择该职工的岗位:" << std::endl;
            std::cout << "1.普通员工" << std::endl;
            std::cout << "2.经理" << std::endl;
            std::cout << "3.总裁" << std::endl;
            std::cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
            case 2:
                worker = new Manager(id, name, 1);
            case 3:
                worker = new Boss(id, name, 1);
            default:
                break;
            }

            // 将创建职工职责,保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 提示添加成功
        std::cout << "成功添加" << addNum << "名新职工!" << std::endl;

        // 保存数据到文件中
        this->save();
    }
    else
    {
        std::cout << "输入有误!" << std::endl;
    }

    // 按任意键后 清屏回到上级目录
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    std::ofstream ofs("empFile.txt", std::ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << ""
            << this->m_EmpArray[i]->m_DeptId << std::endl;
    }

    ofs.close();
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}