/*
编写一个程序，它要求用户首先输入其名，然后输入其姓；
然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。
请使用char数组和头文件cstring中的函数。下面是该程序运行时的情形：
*/
#include <iostream>
#include <cstring>
int main() {
    char Fname[20],Lname[20],name[40];
    std::cout << "Please enter your first name: ";
    std::cin.getline(Fname, 20);
    std::cout << "Please enter your last name: ";
    std::cin.getline(Lname, 20);
    strcpy(name, Lname);
    strcat(name, ", ");
    strcat(name,Fname);
    std::cout << "Your name is: " << name << std::endl;
    return 0;
}
