// 4．编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示：

#include <iostream>
using namespace std;
int main()
{
	int age;
	cout << "Enter your age:";
	cin >> age;
	cout << "Your age in months is " << age*12;
	return 0;
}