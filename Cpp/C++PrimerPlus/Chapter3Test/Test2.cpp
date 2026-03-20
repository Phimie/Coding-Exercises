/*
2．编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。​
（使用3个变量来存储这些信息。​）该程序报告其BMI（Body Mass Index，体重指数）​。
为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸）​，
并将以英寸为单位的身高转换为以米为单位的身高（1英寸=0.0254米）​。
然后，将以磅为单位的体重转换为以千克为单位的体重（1千克=2.2磅）​。
最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。
*/
#include <iostream>
int main() {
	int HeightInFeet;
	int HeightInInches;
	int WeightInPounds;
	std::cout << "Please enter your height in feet:";
	std::cin >> HeightInFeet;
	std::cout << "Please enter your heigh in inches:";
	std::cin >> HeightInInches;
	std::cout << "Please enter your weight in pounds:";
	std::cin >> WeightInPounds;
	std::cout << std::endl << "Your height is " << HeightInFeet * 12 + HeightInInches << " inches" << std::endl;
	const auto HeightInMeter = HeightInFeet * 12 * 0.02545 + HeightInInches * 0.02545;
	const auto WeightInKg = WeightInPounds * 0.45;
	const auto BMI = WeightInKg / (HeightInMeter * HeightInMeter);
	std::cout << "Your BMI is " << BMI << std::endl;
	return 0;
}
