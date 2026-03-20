/*
3．编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和。当用户输入0时，程序结束。
*/

#include <iostream>
int main (){
	long long i=0LL,count=0LL;
	do{
		std::cout << "Please enter a number: ";
		std::cin >> i;
		count += i;
		std::cout << "now, count is "<<count<<std::endl;
	}while(i!=0LL);
	return 0;
}
