#include <iostream>

int main() {
    char choice;

    std::cout << "Please enter one of the following choices£º" << std::endl;
    std::cout << "A.carnivore" << std::endl;
    std::cout << "B.pianist" << std::endl;
    std::cout << "C.tree" << std::endl;
    std::cout << "D.game" << std::endl;

    do {
        std::cout << "Please enter A,B,C or D£º";
        std::cin >> choice;
        choice = toupper(choice);
        if (choice < 'A' || choice > 'D') {
            std::cout << "error!" << std::endl;
        }
    } while (choice < 'A' || choice > 'D');

    switch (choice) {
        case 'A':
            std::cout << "no carnivore" << std::endl;
            break;
        case 'B':
            std::cout << "an apple" << std::endl;
            break;
        case 'C':
            std::cout << "A maple is a tree." << std::endl;
            break;
        case 'D':
            std::cout << "no game!!!!!!!!!" << std::endl;
            break;
    }

    return 0;
}
