#pragma once
#include <iostream>
#include <string>

class Worker
{
public:
    virtual void showInfo() = 0;           // 显示个人信息
    virtual std::string getDeptName() = 0; // 获取岗位名称

    int m_Id;
    std::string m_Name;
    int m_DeptId;
};