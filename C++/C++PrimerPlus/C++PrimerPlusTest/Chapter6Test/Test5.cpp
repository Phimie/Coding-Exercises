#include <iostream>
#include <limits>

int main() {
    double income;
    std::cout << "请输入您的收入（输入负数或非数字结束）：" << std::endl;

    while (std::cin >> income && income >= 0) {
        double tax = 0.0;

        if (income > 35000) {
            tax += (income - 35000) * 0.20;
            income = 35000;
        }
        if (income > 15000) {
            tax += (income - 15000) * 0.15;
            income = 15000;
        }
        if (income > 5000) {
            tax += (income - 5000) * 0.10;
        }

        std::cout << "您的所得税为：" << tax << " tvarps" << std::endl;
        std::cout << "请输入您的收入（输入负数或非数字结束）：" << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
