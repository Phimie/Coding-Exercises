/*
William Wingate���±������������񡣶���ÿ����������������Ҫ��¼������Ϣ��
��������˾�����ƣ������ж��������ɡ���������ֱ������������������
�����һ���ܹ��洢��Щ��Ϣ�Ľṹ������дһ��ʹ�����ֽṹ�����ĳ���
���������û�����������Ϣ��Ȼ����ʾ��Щ��Ϣ����ʹ��cin�������ķ�������cout��
*/



#include <iostream>
#include <string>
struct Pizza {
    std::string companyName;
    double diameter;
    double weight;
};
int main() {
    Pizza Fpizza;
    std::cout << "Enter the name of the pizza company: ";
    std::getline(std::cin, Fpizza.companyName);
    std::cout << "Enter the diameter of the pizza: ";
    std::cin >> Fpizza.diameter;
    std::cin.ignore();
    std::cout << "Enter the weight of the pizza: ";
    std::cin >> Fpizza.weight;
    std::cin.ignore();
    std::cout << "Company Name: " << Fpizza.companyName << "\n"
              << "Diameter: " << Fpizza.diameter << "\n"
              << "Weight: " << Fpizza.weight << "\n";
    return 0;
}
