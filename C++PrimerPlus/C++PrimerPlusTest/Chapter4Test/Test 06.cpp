/*
�ṹCandyBar����3����Ա��������ϰ5��ʾ��
���дһ�����򣬴���һ������3��Ԫ�ص�CandyBar���飬
�������ǳ�ʼ��Ϊ��ѡ���ֵ��Ȼ����ʾÿ���ṹ�����ݡ�
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
