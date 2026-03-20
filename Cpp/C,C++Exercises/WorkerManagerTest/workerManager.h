#pragma once // 防止头文件重复包含
#include <iostream>
#include "worker.h"
#include "worker.cpp"
#include "employee.h"
#include "employee.cpp"
#include "manager.h"
#include "manager.cpp"
#include "boss.h"
#include "boss.cpp"
#include <fstream>

class WorkerManager
{
public:
    WorkerManager(); // 构造函数

    void Show_Menu();

    void exitSystem();

    int m_EmpNum; // 记录职工人数

    Worker **m_EmpArray; // 职工数组指针

    void Add_Emp(); // 添加职工

    void save();

    ~WorkerManager(); // 析构函数
};
