/*
�޸ĳ����嵥4.4��ʹ��C++ string�������char���顣
*/

#include <iostream>
#include <string>
int main(){
	std::string name,dessert;
	std::cout << "Enter your name:\n";
	std::getline(std::cin,name);
	std::cout<<"Enter your favorite desser: \n";
	std:getline(std::cin,dessert);
	std::cout<<"I have some delicious "<<dessert
				<<" for you, "<<name<< ".\n";
	return 0;
}
