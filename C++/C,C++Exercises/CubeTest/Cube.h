#pragma once
#include <iostream>
class Cube
{
public:
    void set_W(double x);
    void set_L(double y);
    void set_H(double z);
    double Cube_S();
    double Cube_V();

private:
    double m_H;
    double m_W;
    double m_L;
};
