#include <iostream>

long long calculate(long long num);

int main() {
    long long num;
    std::cout << "Please enter a number: ";
    std::cin >> num;

    std::cout << "The result is: " << calculate(num) << std::endl;
    return 0;
}

long long calculate(long long num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * calculate(num - 1);
    }
}
