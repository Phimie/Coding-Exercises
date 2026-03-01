/*
结构CandyBar包含3个成员，如编程练习5所示。
请编写一个程序，创建一个包含3个元素的CandyBar数组，
并将它们初始化为所选择的值，然后显示每个结构的内容。
*/


#include <iostream>
#include <string>

struct CandyBar {
    std::string brand;
    double weight;
    int calorie;
};
int main() {
    CandyBar myCandyBars[3] = {
        {"Mars", 58.0, 240},
        {"Snickers", 52.5, 280},
        {"Hershey", 45.0, 210}
    };
    for (int i = 0; i < 3; ++i) {
        std::cout << "Brand: " << myCandyBars[i].brand
                  << ", Weight: " << myCandyBars[i].weight
                  << "g, Calorie: " << myCandyBars[i].calorie
                  << std::endl;
    }
    return 0;
}
