/*
7．编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）​）​，
然后将其转换为美国风格的耗油量—每加仑多少英里。
注意，除了使用不同的单位计量外，美国方法（距离/燃料）与欧洲方法（燃料/距离）相反。
100公里等于62.14英里，1加仑等于3.875升。因此，19mpg大约合12.4l/100km，l27mpg大约合8.71/100km。
*/

#include <iostream>
int main() {
    double FuelConsumptionPer100Km;
    std::cout << "Enter the fuel consumption in liters per 100 kilometers: ";
    std::cin >> FuelConsumptionPer100Km;
    double gallons = FuelConsumptionPer100Km / 3.78541; // 每加仑对应的升数
    double milesPerGallon = 62.14 / gallons;    // 100*0.6214
    std::cout << "The fuel consumption in miles per gallon is: " << milesPerGallon << std::endl;




	return 0;
}



