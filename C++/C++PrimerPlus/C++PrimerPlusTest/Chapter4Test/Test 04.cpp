/*
编写一个程序，它要求用户首先输入其名，再输入其姓；
然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。
请使用string对象和头文件string中的函数。下面是该程序运行时的情形：
*/

#include <iostream>
#include <string>
int main() {
    std::string Fname, Lname, name;
    std::cout << "Please enter your first name: ";
    std::getline(std::cin, Fname);
    std::cout << "Please enter your last name: ";
    std::getline(std::cin, Lname);
    name = Lname + ", " + Fname;
    std::cout << "Your name: " << name << std::endl;
    return 0;
}
