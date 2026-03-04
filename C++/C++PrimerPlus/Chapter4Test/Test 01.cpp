//编写一个C++程序，如下述输出示例所示的那样请求并显示信息：[插图]
//注意，该程序应该接受的名字包含多个单词。
//另外，程序将向下调整成绩，即向上调一个字母。假设用户请求A、B或C，所以不必担心D和F之间的空档。
#include <iostream>
#include <string>
int main() {
    std::string Fname, Lname;
    char Grade;
    int age;
    std::cout << "What is your first name? ";
    std::getline(std::cin, Fname);
    std::cout << "What is your last name? ";
    std::getline(std::cin, Lname);
    std::cout << "What letter grade do you deserve? ";
    std::cin.get(Grade);
    std::cin.ignore();
    std::cout << "What is your age? ";
    std::cin >> age;
    std::cout << "Name: " << Lname << ", " << Fname << "\n"
              << "Grade: " << (char)(Grade+1) << "\n"
              << "Age: " << age << std::endl;
    return 0;
}
