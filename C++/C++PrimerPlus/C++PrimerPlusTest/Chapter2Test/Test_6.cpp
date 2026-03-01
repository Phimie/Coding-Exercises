/*
6．编写一个程序，其main( )调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）。该程序按下面的格式要求用户输入光年值，并显示结果：


天文单位是从地球到太阳的平均距离（约150000000公里或93000000英里），光年是光一年走的距离（约10万亿公里或6万亿英里）（除太阳外，最近的恒星大约离地球4.2光年）。请使用double类型（参见程序清单2.4），转换公式为：

1光年=63240天文单位
*/

#include <iostream>
using namespace std;
double transfer(double);
int main()
{
	double num_lightyears;
	cout << "Enter the number of light years: ";
	cin >> num_lightyears;
	double outcome = transfer(num_lightyears);
	cout << num_lightyears<<" light years " << " = " << outcome << " astronomical units";
	return 0;
}

double transfer(double num_lightyears)
{
	return num_lightyears * 63240;
}