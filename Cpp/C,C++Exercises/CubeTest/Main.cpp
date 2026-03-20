#include <iostream>
#include <string>
#include "Cube.h"
int main()
{
    Cube cube1;
    cube1.set_H(3.0);
    cube1.set_L(2.0);
    cube1.set_W(4.0);
    std::cout << cube1.Cube_S() << std::endl;
    std::cout << cube1.Cube_V() << std::endl;
    system("pause");
    return 0;
}