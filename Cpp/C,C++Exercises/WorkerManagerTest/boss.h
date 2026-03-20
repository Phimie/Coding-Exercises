#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Boss : public Worker
{
public:
    Boss(int id, std::string name, int dId);

    // 重写函数:显示个人信息
    virtual void showInfo();

    // 重写函数:获取职工岗位名称
    virtual std::string getDeptName();
};