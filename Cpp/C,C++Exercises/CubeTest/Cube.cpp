#include "Cube.h"
void Cube::set_W(double x)
{
    m_W = x;
}
void Cube::set_L(double y)
{
    m_L = y;
}
void Cube::set_H(double z)
{
    m_H = z;
}
double Cube::Cube_S()
{
    return (m_H * m_L + m_H * m_W + m_L * m_W) * 2;
}
double Cube::Cube_V()
{
    return (m_H * m_L * m_W);
}
