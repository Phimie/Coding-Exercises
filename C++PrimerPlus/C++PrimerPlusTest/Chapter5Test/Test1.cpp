/*
1����дһ��Ҫ���û��������������ĳ���
�ó��򽫼��㲢�������������֮�䣨�������������������������ĺ͡���
������������С�����������磬����û��������2��9�������ָ��2��9֮�����������ĺ�Ϊ44��
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
	std::cout << num1_<<"~"<<num2<<"֮�������������Ϊ"<<count<<std::endl;
	return 0;
}
