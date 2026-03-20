//7．编写一个程序，要求用户输入小时数和分钟数。在main( )函数中，将这两个值传递给一个void函数，后者以下面这样的格式显示这两个值：

#include <iostream>
using namespace std;
void time(int hours, int minutes);
int main()
{
	int hours;
	int minutes;
	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	time(hours,minutes);
	return 0;
}
void time(int hours, int minutes)
{
	cout << "Time: " << hours << ":" << minutes;
}