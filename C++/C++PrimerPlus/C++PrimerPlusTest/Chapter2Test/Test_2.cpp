//2．编写一个C++程序，它要求用户输入一个以long为单位的距离，然后将它转换为码（一long等于220码）。
#include <iostream>
using namespace std;
int main()
{
	cout << "Please type a namber (long)" << endl;
	int num;
	cin >> num;
	cout << num * 220 << endl;
	return num*220;
}