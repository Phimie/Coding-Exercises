/*
3����дһ��Ҫ���û��������ֵĳ���ÿ������󣬳��򶼽����浽ĿǰΪֹ������������ۼƺ͡����û�����0ʱ�����������
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
