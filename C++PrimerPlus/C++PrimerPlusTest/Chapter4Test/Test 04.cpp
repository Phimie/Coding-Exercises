/*
��дһ��������Ҫ���û������������������������գ�
Ȼ�����ʹ��һ�����źͿո��պ���������������洢����ʾ��Ͻ����
��ʹ��string�����ͷ�ļ�string�еĺ����������Ǹó�������ʱ�����Σ�
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
