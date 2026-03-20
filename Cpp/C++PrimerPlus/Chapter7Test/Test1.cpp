#include <iostream>
double compute(double x, double y);

int main() {
    double num1, num2;
    while (true) {
        std::cout << "Please enter the first number: ";
        std::cin >> num1;
        std::cout << "Please enter the second number: ";
        std::cin >> num2;
        if (num1 == 0 || num2 == 0) {
            std::cout << "Over!" << std::endl;
            break;
        }
        double result = compute(num1, num2);
        std::cout << result << std::endl;
    }
    return 0;
}

double compute(double x, double y) {
    return 2.0 * x * y / (x + y);
}
