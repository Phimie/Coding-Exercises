/*
��дһ��������Ҫ���û���������������Ȼ���������գ�
Ȼ�����ʹ��һ�����źͿո��պ���������������洢����ʾ��Ͻ����
��ʹ��char�����ͷ�ļ�cstring�еĺ����������Ǹó�������ʱ�����Σ�
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
