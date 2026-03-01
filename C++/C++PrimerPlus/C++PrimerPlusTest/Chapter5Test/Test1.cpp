/*
1．编写一个要求用户输入两个整数的程序。
该程序将计算并输出这两个整数之间（包括这两个整数）所有整数的和。这
里假设先输入较小的整数。例如，如果用户输入的是2和9，则程序将指出2～9之间所有整数的和为44。
*/

#include <iostream>
int main (){
	int num1,num2,count=0,num1_;
	std::cout<<"Please enter the first number: ";
	std::cin >> num1;
	num1_=num1;
	std::cout <<std::endl<< "Please enter the second number: ";
	std::cin >> num2;
	std::cout << std::endl;
	for (;num1<=num2;num1++){
		count +=num1;
	}
	std::cout << num1_<<"~"<<num2<<"之间的所有整数和为"<<count<<std::endl;
	return 0;
}
