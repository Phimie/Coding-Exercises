/*
��ɱ����ϰ6����ʹ��new����̬�������飬
����������һ������3��Ԫ�ص�CandyBar���顣
*/


#include <iostream>
#include <string>
struct CandyBar {
    std::string brand;
    double weight;
    int calories;
};

int main() {
	int numberOfCandies;
	std::cout << "Please enter the number of candies: ";
	std::cin >> numberOfCandies;
    CandyBar* candyBars = new CandyBar[numberOfCandies];
    for (int i = 0;i<numberOfCandies;i++){
	    std::cout << "Enter the brand of the candy "<<i<<":  ";
	    std::cin >> candyBars[i].brand;
	    std::cin.ignore();
	    std::cout << "Enter the weight of the candy "<<i<<":  ";
	    std::cin >> candyBars[i].weight;
	    std::cin.ignore();
	    std::cout << "Enter the calories of the candy "<<i<<":  ";
	    std::cin >>  candyBars[i].calories;
	}
    for (int i = 0; i < numberOfCandies; ++i) {
        std::cout << "Brand: " << candyBars[i].brand
                  << ", Weight: " << candyBars[i].weight
                  << "g, Calories: " << candyBars[i].calories
                  << std::endl;
    }

    delete[] candyBars;

    return 0;
}
