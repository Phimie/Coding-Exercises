/*
2��ʹ��array���󣨶��������飩��long double��������long long�����±�д�����嵥5.4��������100!��ֵ��
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
