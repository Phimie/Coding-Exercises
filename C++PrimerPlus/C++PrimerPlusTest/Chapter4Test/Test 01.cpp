//��дһ��C++�������������ʾ����ʾ������������ʾ��Ϣ��[��ͼ]
//ע�⣬�ó���Ӧ�ý��ܵ����ְ���������ʡ�
//���⣬�������µ����ɼ��������ϵ�һ����ĸ�������û�����A��B��C�����Բ��ص���D��F֮��Ŀյ���
#include <iostream>
#include <string>
int main() {
    std::string Fname, Lname;
    char Grade;
    int age;
    std::cout << "What is your first name? ";
    std::getline(std::cin, Fname);
    std::cout << "What is your last name? ";
    std::getline(std::cin, Lname);
    std::cout << "What letter grade do you deserve? ";
    std::cin.get(Grade);
    std::cin.ignore();
    std::cout << "What is your age? ";
    std::cin >> age;
    std::cout << "Name: " << Lname << ", " << Fname << "\n"
              << "Grade: " << (char)(Grade+1) << "\n"
              << "Age: " << age << std::endl;
    return 0;
}
