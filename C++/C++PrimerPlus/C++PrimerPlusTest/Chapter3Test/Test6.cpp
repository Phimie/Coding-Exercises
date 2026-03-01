/*
．编写一个程序，要求用户输入驱车里程（英里）和使用汽油量（加仑）​，
然后指出汽车耗油量为一加仑的里程。
如果愿意，也可以让程序要求用户以公里为单位输入距离，
并以升为单位输入汽油量，然后指出欧洲风格的结果—即每100公里的耗油量（升）​。
*/

#include <iostream>
int main() {
	double kilometers;
	float liters;
	std::cout << "Enter the distance in kilometers: ";
	std::cin >> kilometers;
	std::cout << "Enter oil fuel in liters: ";
	std::cin >> liters;
	std::cout << (liters / kilometers) * 100 << " liters per 100 kilometers." << std::endl;
	return 0;
}
