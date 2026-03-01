#include <iostream>
#include <stdio.h>
int main() {
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day,day_of_year = 0;
	std::cout << "请分别输入年月日" << std::endl;
	std::cin >> year;
	std::cin >> month;
	std::cin >> day;
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		printf("输入的日期不合法，请检查后再试。\n");
		return 1;
	}
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		days_in_month[1] = 29;
	}
	for (int i = 0; i < month - 1; i++) {
		day_of_year += days_in_month[i];
	}
	day_of_year += day;
	printf("%d年%d月%d日是这一年的第%d天。\n", year, month, day, day_of_year);
	return 0;
}