/*
5．编写一个程序，要求用户输入全球当前的人口和美国当前的人口（或其他国家的人口）​
将这些信息存储在long long变量中，并让程序显示美国（或其他国家）的人口占全球人口的百分比
*/

#include <iostream>
int main() {
	long long WorldPopulation;
	long long USPopulation;
	std::cout << "Enter the world\'s population: ";
	std::cin >> WorldPopulation;
	std::cout << "Enter the population of the US: ";
	std::cin >> USPopulation;
	std::cout << "The population of the US is " << static_cast<double>(USPopulation) / WorldPopulation * 100 << "% of the world population." << std::endl;

	return 0;
}
