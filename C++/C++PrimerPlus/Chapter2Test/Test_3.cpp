/*
3．编写一个C++程序，它使用3个用户定义的函数（包括main( )），并生成下面的输出：
其中一个函数要调用两次，该函数生成前两行；另一个函数也被调用两次，并生成其余的输出。
*/
#include <iostream>
using namespace std;
void First(void);
void Second(void);
int main()
{
	First();
	First();
	Second();
	Second();
	return 0;
}
void First()
{
	cout << "Three blind mice" << endl;
}
void Second()
{
	cout << "See how they run" << endl;
}