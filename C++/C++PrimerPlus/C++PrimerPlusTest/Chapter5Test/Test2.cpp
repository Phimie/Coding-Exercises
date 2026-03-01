/*
2．使用array对象（而不是数组）和long double（而不是long long）重新编写程序清单5.4，并计算100!的值。
*/

#include <array>
#include <iostream>
int main (){
	std::array<long double,100> num;
	num[0] = 1.0L;
	for (int i = 1; i < 100; ++i) {
	    num[i] = num[i - 1] * (long double)i;
	}
	std::cout << "100! = " << num[99] << std::endl;
	return 0;
}
