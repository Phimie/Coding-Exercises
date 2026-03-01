/*
3．编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。
1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。
*/

#include <iostream>
int main() {
	int degrees;
	int minutes;
	int seconds;
	std::cout << "Enter a latitude in degrees, minutes , and seconds;" << std::endl;
	std::cout << "First ,enter the degrees: ";
	std::cin >> degrees;
	std::cout << "Next, enter the minutes of arc: ";
	std::cin >> minutes;
	std::cout << "Finally, enter the seconds of arc: ";
	std::cin >> seconds;
	const double result = degrees + minutes * 0.01667 + seconds * 0.0002777777777777778;
	std::cout << degrees << " degrees," << minutes << " minutes," << seconds << " seconds = " << result << " degrees" << std::endl;
	return 0;
}