/*
4．编写一个程序，要求用户以整数方式输入秒数（使用long或long long变量存储)
然后以天、小时、分钟和秒的方式显示这段时间。
使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。
*/


#include <iostream>	
int main() {
	const long SECONDS_MINUTE = 60;
	const long SECONDS_HOUR = 3600;
	const long SECONDS_DAY = 86400;
	long long AllSeconds;
	std::cout << "Enter the number of seconds: ";
	std::cin >> AllSeconds;
	long days = AllSeconds / SECONDS_DAY;
	long AllSeconds2 = AllSeconds % SECONDS_DAY;
	long hours = AllSeconds2 / SECONDS_HOUR;
	long AllSeconds3 =  AllSeconds2 % SECONDS_HOUR;
	long minutes = AllSeconds3 / SECONDS_MINUTE;
	long seconds = AllSeconds3 % SECONDS_MINUTE;
	std::cout << AllSeconds << " seconds = " << days << " days,"<< hours << " hours,"<< minutes << " minutes, "<< seconds << " seconds." << std::endl;
	return 0;
}
