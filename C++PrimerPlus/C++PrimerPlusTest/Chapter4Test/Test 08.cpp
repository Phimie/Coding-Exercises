/*
��ɱ����ϰ7����ʹ��new��Ϊ�ṹ�����ڴ棬����������һ���ṹ������
���⣬�ó��������������������˾����֮ǰ�����������ֱ����
*/


#include <iostream>
#include <string>
struct Pizza {
    double diameter;
    std::string companyName;
    double weight;
};
int main() {
    Pizza* Fpizza = new Pizza;
    std::cout << "Enter the diameter of the pizza: ";
    std::cin >> Fpizza->diameter;
    std::cin.ignore();
    std::cout << "Enter the name of the pizza company: ";
    std::getline(std::cin, Fpizza->companyName);
    std::cout << "Enter the weight of the pizza: ";
    std::cin >> Fpizza->weight;
    std::cin.ignore();
    std::cout << "\nDiameter: " << Fpizza->diameter << "\n"
              << "Company Name: " << Fpizza->companyName << "\n"
              << "Weight: " << Fpizza->weight << "\n";
    delete Fpizza;
    return 0;
}
