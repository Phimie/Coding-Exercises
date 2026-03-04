/*
编写一个程序，让用户输入三次40码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩）?，
并显示次数和平均成绩。请使用一个array对象来存储数据（如果编译器不支持array类，请使用数组）?。
*/
#include <iostream>
#include <vector> //我打算用vector
int main() {
    std::vector<double> times;
    double time;
    int count = 0;
    std::cout << "请输入三次40米跑的成绩（单位：秒）：" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cin >> time;
        times.push_back(time);
        ++count;
    }
    double sum;
    for (double t : times) {
        sum += t;
    }
    double averageTime = sum / count;
    std::cout << "总共输入了 " << count << " 次成绩。" << std::endl;
    std::cout << "平均成绩是：" << averageTime << " 秒。" << std::endl;
    return 0;
}
