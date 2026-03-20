/*
5．编写一个程序，其中的main( )调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。该程序按下面的格式要求用户输入摄氏温度值，并显示结果：


下面是转换公式：

华氏温度 = 1.8×摄氏温度 + 32.0
*/
#include <iostream>
using namespace std;
double n(double);
int main()
{
	double m;
	cout << "Please enter a Celsius value:";
	cin >>m;
	double outcome = n(m);
	cout << m << " degrees Celsius is " << outcome << " degrees Fahrenheit.";
	return 0;
}
double n(double m)
{
	return m * 1.8 + 32;
}

