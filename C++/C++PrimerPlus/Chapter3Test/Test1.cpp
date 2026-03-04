//1．编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸）​，然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。
#include <iostream>
int main() {
	int height;
	std::cout << "请输入你的身高(单位英尺):______________________";
	std::cin >> height;
	const int HEIGHT2 = height * 12;
	std::cout << "你的身高是:" << height << "英尺,即" << HEIGHT2 << "英寸" << std::endl;
	return 0;
}